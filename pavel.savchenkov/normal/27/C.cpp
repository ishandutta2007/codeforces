#include <cstdio>
#include <vector>

#define mp make_pair

const int INF = 1 << 31;

using namespace std;

struct segm_tree
{
 vector < pair <int, int> > t;
 int sz;
 
 segm_tree() {};
 
 segm_tree(const vector <int> & a) 
 {
   sz = 1; while (sz < (int)a.size()) sz <<= 1; 
   t.assign(sz * 2, mp(0, 0));
   build(a, 1, 0, sz - 1);
 }

 void build(const vector <int> & a, int v, int tl, int tr)
 {
  if  (tl == tr) { if  (tl < (int)a.size()) t[v] = mp(a[tl], a[tl]); else t[v] = mp(INF, -INF); return; } 
  int tm = (tl + tr) >> 1;
  build(a, v + v, tl, tm);
  build(a, v + v + 1, tm + 1, tr);
  t[v].first = min(t[v + v].first, t[v + v + 1].first);
  t[v].second = max(t[v + v].second, t[v + v + 1].second);
 };

 int getmin(int v, int tl, int tr, int l, int r)
 {
  if  (tl == l && tr == r)  return t[v].first;
  int tm = (tl + tr) >> 1;
  if  (r <= tm) return getmin(v + v, tl, tm, l, r);
  if  (l > tm) return getmin(v + v + 1, tm + 1, tr, l, r);
  return min( getmin(v + v, tl, tm, l, tm), getmin(v + v + 1, tm + 1, tr, tm + 1, r) );
 };

 int getmax(int v, int tl, int tr, int l, int r)
 {
  if  (tl == l && tr == r)  return t[v].second;
  int tm = (tl + tr) >> 1;
  if  (r <= tm) return getmax(v + v, tl, tm, l, r);
  if  (l > tm) return getmax(v + v + 1, tm + 1, tr, l, r);
  return max( getmax(v + v, tl, tm, l, tm), getmax(v + v + 1, tm + 1, tr, tm + 1, r) );
 };

 int getmin(int l, int r)
 {
  return getmin(1, 0, sz - 1, l, r);
 };

 int getmax(int l, int r)
 {
  return getmax(1, 0, sz - 1, l, r);
 };
 
};

int n;
vector <int> a;
segm_tree tr;

int main() {
 scanf("%d", &n);
 a.assign(n, 0);
 for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 tr = segm_tree(a);
 
 for (int i = 1; i < n - 1; i++)
  if  (tr.getmin(0, i - 1) < a[i] && tr.getmin(i + 1, n - 1) < a[i] || tr.getmax(0, i - 1) > a[i] && tr.getmax(i + 1, n - 1) > a[i])
  {
   int mi1 = 0; int mi2 = i + 1; int ma1 = 0; int ma2 = i + 1;
   for (int j = 0; j < i; j++)
   {
    if  (a[mi1] > a[j]) mi1 = j;
    if  (a[ma1] < a[j]) ma1 = j;
   }
   for (int j = i + 1; j < n; j++)
   {
    if  (a[mi2] > a[j]) mi2 = j;
    if  (a[ma2] < a[j]) ma2 = j;
   }
  
  printf("3\n");
  if  (a[mi1] < a[i] && a[mi2] < a[i]) { printf("%d %d %d\n", mi1 + 1, i + 1, mi2 + 1); return 0; }
  printf("%d %d %d\n", ma1 + 1, i + 1, ma2 + 1); return 0;
 }
 
 puts("0");
 return 0;
}
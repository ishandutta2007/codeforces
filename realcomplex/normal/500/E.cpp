#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e6 + 912;
struct Node{
  int lazy;
  int value;
};

Node Tree[N * 4 + 1234];
vector<int> points;
vector<pii> segm;

void merge(int ix){
  Tree[ix].value = Tree[ix * 2].value + Tree[ix * 2 + 1].value;
}

void build(int node, int cl, int cr){
  Tree[node].lazy = 0;
  Tree[node].value = 0;
  if(cl == cr){
    Tree[node].value = segm[cl].se - segm[cl].fi + 1;
    return;
  }
  int md = (cl + cr)/2;
  build(node * 2, cl, md);
  build(node * 2 + 1, md + 1, cr);
  merge(node);
}

void push(int node, int cl, int cr){
  if(Tree[node].lazy){
    if(cl != cr){
      Tree[node * 2].lazy = 1;
      Tree[node * 2 + 1].lazy = 1;
    }
    Tree[node].lazy = 0;
    Tree[node].value = 0;
  }
}

void update(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl and cr <= tr){
    Tree[node].lazy = 1;
    push(node, cl, cr);
    return;
  } 
  int md = (cl + cr)/2;
  update(node * 2, cl, md, tl, tr);
  update(node * 2 + 1, md + 1, cr, tl, tr);
  merge(node);
}

int qry(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl)
    return 0;
  if(cl > tr)
    return 0;
  if(cl >= tl and cr <= tr){
    return Tree[node].value;
  }
  int md = (cl + cr)/2;
  return qry(node * 2, cl, md, tl, tr) + qry(node * 2 + 1, md + 1, cr, tl, tr);
}

int SIZE;

void Update(int cl, int cr){
  int fc = lower_bound(segm.begin(), segm.end(), mp(cl, -1)) - segm.begin();
  int sc = lower_bound(segm.begin(), segm.end(), mp(cr, -1)) - segm.begin();
  update(1, 0, SIZE - 1, fc, sc);
}

int ask(int cl, int cr){
  int fc = lower_bound(segm.begin(), segm.end(), mp(cl, -1)) - segm.begin();
  int sc = lower_bound(segm.begin(), segm.end(), mp(cr, -1)) - segm.begin();
  return qry(1, 0, SIZE - 1, fc, sc);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int l[n], r[n];
  for(int i = 0;i < n; i++ ){
    cin >> l[i] >> r[i];
    r[i] += l[i];
    r[i] -- ;
    points.push_back(l[i]);
    points.push_back(r[i]);
  }
  sort(points.begin(), points.end());
  points.resize(unique(points.begin(), points.end()) - points.begin());
  for(int i = 0;i < points.size(); i ++ ){
    if(i > 0){
      if(points[i] - points[i - 1] > 1){
        segm.push_back(mp(points[i - 1] + 1, points[i] - 1));
      }
    }
    segm.push_back(mp(points[i], points[i]));
  }
  SIZE = segm.size();
  build(1, 0, SIZE-1);
  int q;
  cin >> q;
  vector<pii> st[n];
  int answer[q];
  int li, ri;
  for(int i = 0;i < q;i ++ ){
    cin >> li >> ri;
    --li;
    --ri;
    st[li].push_back(mp(ri, i));
  }
  for(int i = n-1;i >= 0;i -- ){
    Update(l[i], r[i]); 
    for(auto x : st[i]){
      answer[x.se] = ask(l[i], l[x.fi]);
    }
  }
  for(int i = 0;i < q;i ++ ){
    cout << answer[i] << "\n";
  }
  return 0;
}
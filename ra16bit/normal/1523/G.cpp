#include <bits/stdc++.h>
using namespace std;
const int MX=134134,inf=2000000;
int n,m,num,i,j,v[MX],l[MX],r[MX],res[MX];
pair<int,int> a[MX];

struct Node {
  int mn,lft,rgh;
} b[324*MX];

int createnode() {
  b[++num].mn=inf;
  b[num].lft=0;
  b[num].rgh=0;
  return num;
}
void upd(int i, int L, int R, int pos, int v) {
  b[i].mn=min(b[i].mn,v);
  if (L==R) return;
  int h=(L+R)/2;
  if (pos<=h) {
    if (b[i].lft==0) b[i].lft=createnode();
    upd(b[i].lft,L,h,pos,v);
  } else {
    if (b[i].rgh==0) b[i].rgh=createnode();
    upd(b[i].rgh,h+1,R,pos,v);
  }
}
int fmin(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return b[i].mn;
  int h=(L+R)/2,res=inf;
  if (le<=h && b[i].lft) res=min(res,fmin(b[i].lft,L,h,le,min(h,ri)));
  if (ri>h && b[i].rgh) res=min(res,fmin(b[i].rgh,h+1,R,max(h+1,le),ri));
  return res;
}

void init(int i, int L, int R) {
  v[i]=createnode();
  if (L==R) return;
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
}
void add(int i, int L, int R, int le, int ri, int val) {
  upd(v[i],L,n,ri,val);
  if (L==R) return;
  int h=(L+R)/2;
  if (le<=h) add(i*2,L,h,le,ri,val); else add(i*2+1,h+1,R,le,ri,val);
}
int findmin(int i, int L, int R, int le, int ri) {
  if (L==le && R<=ri) return fmin(v[i],L,n,le,ri);
  int h=(L+R)/2,res=inf;
  if (le<=h) res=min(res,findmin(i*2,L,h,le,ri));
  if (ri>h) res=min(res,findmin(i*2+1,h+1,R,max(h+1,le),ri));
  return res;
}
int solve(int le, int ri) {
  if (le>ri) return 0;
  //printf("solve [%d..%d]\n",le,ri);
  int idx=findmin(1,1,n,le,ri);
  //printf("idx=%d\n",idx);
  if (idx==inf) return 0;
  return r[idx]-l[idx]+1+solve(le,l[idx]-1)+solve(r[idx]+1,ri);
}
int main() {
  scanf("%d%d",&n,&m);
  init(1,1,n);
  for (i=0; i<m; i++) {
    scanf("%d%d",&l[i],&r[i]);
    a[i]={r[i]-l[i]+1,i};
  }
  sort(a,a+m);
  for (i=n, j=m-1; i>0; i--) {
    bool was=false;
    for (; j>=0 && a[j].first>=i; --j) {
      was=true;
      add(1,1,n,l[a[j].second],r[a[j].second],a[j].second);
    }
    if (was) res[i]=solve(1,n); else res[i]=res[i+1];
  }
  for (i=1; i<=n; i++) printf("%d\n",res[i]);
  return 0;
}
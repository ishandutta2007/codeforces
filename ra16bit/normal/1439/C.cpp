#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=277277;
struct Node {
  int mn,mx;
  long long sum;
  bool need;
} b[MX*2];
int n,q,i,t,x,y,res,a[MX];
void init(int i, int L, int R) {
  if (L==R) {
    b[i].sum=a[R];
    b[i].mn=a[R];
    b[i].mx=a[R];
    b[i].need=false;
    return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
  b[i].sum=b[i*2].sum+b[i*2+1].sum;
  b[i].mn=min(b[i*2].mn,b[i*2+1].mn);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx);
  b[i].need=false;
}
void updpush(int i, int L, int R, int v) {
  b[i].sum=v*(R-L+1LL);
  b[i].mn=v;
  b[i].mx=v;
  b[i].need=true;
}
void upd(int i, int L, int R, int rgh, int v) {
  if (b[i].mn>v) return;
  if (R<=rgh && b[i].mx<=v) {
    updpush(i,L,R,v);
    return;
  }
  int h=(L+R)/2;
  if (b[i].need) {
    assert(b[i].mn==b[i].mx);
    updpush(i*2,L,h,b[i].mx);
    updpush(i*2+1,h+1,R,b[i].mx);
    b[i].need=false;
  }
  if (b[i*2].mn<=v) upd(i*2,L,h,min(h,rgh),v);
  if (rgh>h) upd(i*2+1,h+1,R,rgh,v);
  b[i].sum=b[i*2].sum+b[i*2+1].sum;
  b[i].mn=min(b[i*2].mn,b[i*2+1].mn);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx);
}
int findlft(int i, int L, int R, int v) {
  if (L==R) return R;
  int h=(L+R)/2;
  if (b[i].need) {
    assert(b[i].mn==b[i].mx);
    updpush(i*2,L,h,b[i].mx);
    updpush(i*2+1,h+1,R,b[i].mx);
    b[i].need=false;
  }
  if (b[i*2].mn<=v) return findlft(i*2,L,h,v);
  return findlft(i*2+1,h+1,R,v);
}
pii resolve(int i, int L, int R, int lft, int v) {
  if (lft>R || b[i].mn>v) return {0,0};
  if (lft<=L && b[i].sum<=v) return {R-L+1,b[i].sum};
  int h=(L+R)/2;
  if (b[i].need) {
    assert(b[i].mn==b[i].mx);
    updpush(i*2,L,h,b[i].mx);
    updpush(i*2+1,h+1,R,b[i].mx);
    b[i].need=false;
  }
  int cnt=0,sv=0;
  if (lft<=h && b[i*2].mn<=v) {
    pii cur=resolve(i*2,L,h,lft,v-sv);
    cnt+=cur.first;
    sv+=cur.second;
    if (lft+cur.first>h && b[i*2+1].mx<=v-sv) {
      cur=resolve(i*2+1,h+1,R,h+1,v-sv);
      cnt+=cur.first;
      sv+=cur.second;
    }
  } else if (b[i*2+1].mn<=v) {
    lft=max(lft,h+1);
    pii cur=resolve(i*2+1,h+1,R,lft,v);
    cnt+=cur.first;
    sv+=cur.second;
  }
  return {cnt,sv};
}
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  init(1,1,n);
  while (q--) {
    scanf("%d%d%d",&t,&x,&y);
    if (t==2) {
      res=0;
      while (y>0 && x<=n) {
        if (b[1].mn>y) break;
        x=max(x,findlft(1,1,n,y));
        //printf("y=%d pos=%d\n",y,x);
        pii cur=resolve(1,1,n,x,y);
        //printf(" cur: %d %d\n",cur.first,cur.second);
        x+=cur.first;
        res+=cur.first;
        y-=cur.second;
      }
      printf("%d\n",res);
    } else upd(1,1,n,x,y);
  }
  return 0;
}
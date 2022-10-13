#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

typedef struct{
  long long val[4];
}stnode;

long long ssize=524288;
stnode stree[1048576],vd;

stnode mg(stnode l,stnode r){
  stnode res;
  res.val[0]=max(l.val[0]+r.val[0],l.val[1]+r.val[2]);
  res.val[1]=max(l.val[0]+r.val[1],l.val[1]+r.val[3]);
  res.val[2]=max(l.val[2]+r.val[0],l.val[3]+r.val[2]);
  res.val[3]=max(l.val[2]+r.val[1],l.val[3]+r.val[3]);
  return res;
}

void upd(long long k,long long a){
  long long ld,rd;
  k+=ssize-1;
  stree[k].val[0]=0;
  stree[k].val[1]=a;
  stree[k].val[2]=-a;
  stree[k].val[3]=0;
  while(k>0){
    k=(k-1)/2;
    ld=2*k+1;
    rd=2*k+2;
    stree[k]=mg(stree[ld],stree[rd]);
  }
}

//call:k=0,l=0,r=ssize
stnode query(long long a,long long b,long long k,long long l,long long r){
  if(r<=a || b<=l){return vd;}
  if(a<=l && r<=b){
    return stree[k];
  }
  else{
    stnode ld,rd;
    ld=query(a,b,k*2+1,l,(l+r)/2);
    rd=query(a,b,k*2+2,(l+r)/2,r);
    return mg(ld,rd);
  }
}

void outres(stnode v){
  long long res=v.val[0];
  res=max(res,v.val[1]);
  res=max(res,v.val[2]);
  res=max(res,v.val[3]);
  cout << res << '\n';
  return;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vd.val[0]=0;
  vd.val[1]=-llinf;
  vd.val[2]=-llinf;
  vd.val[3]=0;
  int t,a[524288];
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    stnode res;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      upd(i,a[i]);
    }
    res=query(1,n+1,0,0,ssize);
    outres(res);
    while(q>0){
      q--;
      int l,r;
      cin >> l >> r;
      swap(a[l],a[r]);
      upd(l,a[l]);
      upd(r,a[r]);
      res=query(1,n+1,0,0,ssize);
      outres(res);
    }
  }
  return 0;
}
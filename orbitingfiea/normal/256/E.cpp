#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define mod 777777777
using namespace std;

int n,m,a[3][3];
struct Node{
  int v[3][3];
}tr[330333],an,tmp;

void U(int &x,int y){
  x+=y; if (x>=mod) x-=mod;
}

Node onion(Node x,Node y){
  static Node res;
  memset(res.v,0,sizeof res.v);
  for (int i=0;i<3;++i)
    for (int j=0;j<3;++j)
      for (int ii=0;ii<3;++ii)
	for (int jj=0;jj<3;++jj)
	  U(res.v[i][jj],(ll)x.v[i][j]*y.v[ii][jj]*a[j][ii]%mod);
  return res;
}

void build(int x,int l,int r){
  if (l==r){
    for (int i=0;i<3;++i) tr[x].v[i][i]=1;
    return;
  }
  int mid=l+r>>1;
  build(x<<1,l,mid); build(x<<1|1,mid+1,r);
  tr[x]=onion(tr[x<<1],tr[x<<1|1]);
}

void cg(int x,int l,int r,int p,int v){
  if (l==r){
    if (~v){
      for (int i=0;i<3;++i) tr[x].v[i][i]=0;
      tr[x].v[v][v]=1;
    }else{
      for (int i=0;i<3;++i) tr[x].v[i][i]=1;
    }
    return;
  }
  int mid=l+r>>1;
  if (p<=mid) cg(x<<1,l,mid,p,v);
  else cg(x<<1|1,mid+1,r,p,v);
  tr[x]=onion(tr[x<<1],tr[x<<1|1]);
}

int main(){
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for (int i=0;i<3;++i) for (int j=0;j<3;++j) cin>>a[i][j];
  build(1,1,n);
  for (int p,t,ans;m--;){
    cin>>p>>t;
    cg(1,1,n,p,t? t-1: -1);
    ans=0; an=tr[1];
    for (int i=0;i<3;++i)
      for (int j=0;j<3;++j)
	U(ans,an.v[i][j]);
    cout<<ans<<endl;
  }
}
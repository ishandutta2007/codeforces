#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
map<ll,int> zip;

const int MAX_N=(1<<17);
const ll INF=1e17;
int nn=1<<17;
pii dat[2*MAX_N-1];

void update(int k,pii a){
  k+=nn-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=max(dat[k*2+1],dat[k*2+2]);
  }
}

//(l,r,0,0,nn)
pii query(int a,int b,int k,int l,int r){
  if(r<=a || b<=l)return pii(0,-1);
  if(a<=l && r<=b) return dat[k];
  else{
    pii vl=query(a,b,k*2+1,l,(l+r)/2);
    pii vr=query(a,b,k*2+2,(l+r)/2,r);
    return max(vl,vr);
  }
}

int pare[112345];

void trace(int p){
  if(pare[p]==-1){
    cout<<p+1<<" ";
    return;
  }else{
    trace(pare[p]);
    cout<<p+1<<" ";
    return;
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k,n,d;
  fill(pare,pare+112345,-1);
  fill(dat,dat+2*MAX_N-1,pii(0,-1));
  cin>>n>>d;
  vector<ll> ori(n),unzip,h(n);
  rep(i,n){
    cin>>ori[i];
  }
  unzip=ori;
  sort(all(unzip));
  unzip.erase(unique(all(unzip)) ,unzip.end());
  rep(i,unzip.size())
    zip[unzip[i]]=i;
  rep(i,n){
    h[i]=zip[ori[i]];
  }
//  for(auto tmp:zip)cout<<tmp.X<<","<<tmp.Y<<" ";cout<<endl;
  int l,r,re=0,rei;
  zip[-INF]=-1;
  zip[INF]=n;
  pii v;
  rep(i,n){
    l=(--zip.upper_bound(ori[i]-d))->Y;
    r=(zip.lower_bound(ori[i]+d))->Y;
    //cout<<m<<","<<l<<","<<r<<endl;
    v=max(query(0,l+1,0,0,nn) , query(r,n,0,0,nn));
    v.X++;
    if(re<v.X){
      re=v.X;
      rei=i;
    }
    pare[i]=v.Y;
    if(query(h[i],h[i]+1,0,0,nn)<v)
      update(h[i],pii(v.X,i));
//    cout<<i<<"<"<<v.X<<","<<v.Y<<endl;
  }
//  rep(i,10)cout<<pare[i]<<" ";cout<<endl;
 // cout<<rei<<endl;
  cout<<re<<endl;
  trace(rei);
  return 0;
}
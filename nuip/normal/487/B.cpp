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
#include<iomanip>
#include<numeric>
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
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int MAX_N=(1<<17);
const ll INF=1e9+10;
int nn=MAX_N;

struct Seg{
 ll sum,mx,mn;
  Seg(ll d=0,ll a=-INF,ll b=INF){
    sum=d,mx=a,mn=b;
  }
};

Seg dat[2*MAX_N-1];
Seg SegE=Seg();

Seg operator+(Seg l,Seg r){
  Seg seg;
  seg.sum=l.sum+r.sum;
  seg.mx=max(l.mx,r.mx);
  seg.mn=min(l.mn,r.mn);
  return seg;
}

void upd(int k,Seg a){
  k+=nn-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}
//(l,r,0,0,nn)
Seg query(int a,int b,int k,int l,int r){
  if(r<=a || b<=l)return SegE;
  if(a<=l && r<=b) return dat[k];
  return query(a,b,k*2+1,l,(l+r)/2) + query(a,b,k*2+2,(l+r)/2,r);
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,s,len;
  cin>>n>>s>>len;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
    upd(i,Seg(a[i],a[i],a[i]));
  }
  int re,l,r,mn,mx,mx2,mn2;
  re=l=r=-1;
  for(re=0;r<n-1;re++){
    int p=r+1,rr=r,f=0;
    mx=mn=mn2=mx2=a[p];
    while(p<n){
      mx2=max(mx2,a[p]);
      mn2=min(mn2,a[p]);
      if(mx2-mn2>s)
        break;
      mx=mx2;
      mn=mn2;
      p++;
    }
    p--;
 //   cout<<"p:"<<p<<endl;
    while(p-r<len){
      if(l>=r)
        f=1;
      mx=max(mx,a[r]);
      mn=min(mn,a[r]);
      r--;
      if(mx-mn>s)
        f=1;
    }
    if(f){
 //     cout<<l<<","<<r<<","<<mx<<","<<mn<<endl;
      cout<<-1<<endl;
      return 0;
    }
    r=p;
    int m;
    while(l<n){
      l++;
      Seg tmp=query(l,l+len,0,0,nn);
      if(tmp.mx-tmp.mn<=s)
        break;
    }
    l+=len-1;
  //  cout<<l<<","<<r<<endl;
  }
  cout<<re<<endl;
  return 0;
}
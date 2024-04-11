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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define int long long

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int n,m,s;
vector<pii> bug;
vector<int> re,pas,abi;
const int MAX_N=(1<<18);
const int INF=1e9+10;
int nn=MAX_N;

struct Seg{
  ll mn,ind,abi;
  Seg(ll d=INF,ll i=INF,ll a=INF){
    mn=d;
    ind=i;
    abi=a;
  }
  static Seg e;
};
vector<Seg> dat(2*MAX_N-1);
Seg Seg::e=Seg();

Seg operator+(Seg l,Seg r){
  if(l.mn>r.mn)
    swap(l,r);
  return l;
}

template<class T> void upd(vector<T> &dat,int k,T a){
  k+=nn-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}
template<class T> void add(vector<T> &dat,ll k,ll a){
  k+=nn-1;
  dat[k].mn+=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

//(l,r,0,0,nn)
template<class T> T query(vector<T> &dat,int a,int b,int k,int l,int r){
  if(r<=a || b<=l)return T::e;
  if(a<=l && r<=b) return dat[k];
  return query(dat,a,b,k*2+1,l,(l+r)/2) + query(dat,a,b,k*2+2,(l+r)/2,r);
}

int solve(int d){
  int ok=0,i,j,k,sum=0;
  vector<int> used;
  for(ok=0;ok<m;ok+=d){
    Seg tmp=query(dat,bug[ok].X,n+m+10,0,0,nn);
    if(tmp.mn>=INF){
      sum+=s+10;
      break;
    }
    //  cout<<tmp.ind+1<<":";
    rep(i,min(d,m-ok)){
      re[bug[ok+i].Y]=tmp.ind+1;
      //      cout<<bug[ok+i].Y<<",";
    }//cout<<endl;
    sum+=tmp.mn;
    add(dat,tmp.abi,INF);
    used.pb(tmp.abi);
  }
  rep(i,used.size())
    add(dat,used[i],-INF);
  //  cout<<sum<<endl;
  return sum<=s;
}

 main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  cin>>n>>m>>s;
  abi.resize(n),pas.resize(n),bug.resize(m),re.resize(m);
  rep(i,m)
    cin>>bug[i].X;
  rep(i,n)
    cin>>abi[i];
  rep(i,n)
    cin>>pas[i];
  vector<pii> zip=bug;
  rep(i,n)
    zip.pb(pii(abi[i],m+i));
  sort(all(zip));
  rep(i,m){
    bug[i].X=lower_bound(all(zip),bug[i])-zip.begin();
    bug[i].Y=i;
  }
  rep(i,n)
    abi[i]=lower_bound(all(zip),pii(abi[i],m+i))-zip.begin();
  sort(rall(bug));
  rep(i,n)
    upd(dat,abi[i],Seg(pas[i],i,abi[i]));
  int l=0,r=m+10,med;
  while(r-l>1){
    //    cout<<l<<","<<r<<endl;
    med=(r+l)/2;
    if(solve(med))
      r=med;
    else
      l=med;
  }
  //  cout<<r<<endl;
  if(!solve(r)){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
    //   solve(r);
    rep(i,m)
      cout<<re[i]<<" ";cout<<endl;
  }
  return 0;
}
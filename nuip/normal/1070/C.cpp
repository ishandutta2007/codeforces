#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X)=(0);(X)<(Y);++(X))
#define REP rep
#define rrep(X,Y) for(int (X)=(Y)-1;(X)>=0;++(X))
#define all(x) (x).begin(),(x).end()
#define eb pb

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for(int (X)=S;(X)<(Y);++(X))
#define rreps(X,S,Y) for(int (X)=(Y)-1;(X)>=(S);--(X))

template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

ll sum(const vector<ll> &bit,int i){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(vector<ll> &bit,int i,ll x){ ++i;
  while(i<bit.size()){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n,t,m;
  cin>>n>>t>>m;
  vector<vector<pii>> ad(n+1);
  rep(i,m){
    int l,r,c,p;
    cin>>l>>r>>c>>p; --l;
    ad[l].eb(p,c);
    ad[r].eb(p,-c);
  }
  const int N=1000100;
  vector<ll> sz(N),cost(N);
  ll re=0;
  rep(i,n){
    for(pii p:ad[i]){
      add(sz,p.X,p.Y);
      add(cost,p.X,1ll*p.X*p.Y);
    }
    if(sum(sz,N)<=t){
      re+=sum(cost,N);
      continue;
    }
    int l=0,r=N;
    while(r-l>1){
      int m=(l+r)/2;
      (sum(sz,m)>t?r:l)=m;
    }
    re+=sum(cost,l);
    re+=r*(t-sum(sz,l));
  }
  cout<<re<<endl;
  return 0;
}
#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for( int (X) =(Y)-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

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
#define rreps(X,S,Y) for(int (X) =(Y)-1; (X)>=(S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n;
  cin>>n;
  int N=n;
  vector<pii> ps;
  for(ll i=2;i*i<=n;++i){
    if(n%i) continue;
    ps.eb(i,0);
    while(n%i==0){
      n/=i;
      ++ps.back().Y;
    }
  }
  if(n>1) ps.eb(n,1);
  if(ps.size()<=1){
    cout<<"NO"<<endl;
    return 0;
  }
  n=N;
  int p=ps[0].X;
  int q=ps[1].X;
  int s=0;
  // cout<<p<<","<<q<<","<<s<<endl;
  while(s%p!=(n-1)%p){
    s+=q;
  }
  // cout<<p<<","<<q<<","<<s<<endl;
  cout<<"YES"<<endl;
  vector<pii> re;
  if(s){
    int p=s,q=n;
    int g=__gcd(p,q);
    re.eb(p/g,q/g);
  }
  if(n-1-s){
    int p=n-1-s,q=n;
    int g=__gcd(p,q);
    re.eb(p/g,q/g);
  }
  cout<<re.size()<<endl;
  for(pii p:re) cout<<p.X<<" "<<p.Y<<endl;
  return 0;
}
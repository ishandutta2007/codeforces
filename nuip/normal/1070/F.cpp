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
const LL SIZE=5e5;
LL a1,a2,a3;
LL A[SIZE];
LL aa[4];
vector<LL> v[4];
int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n;
  cin >> n;
  LL ans=0;
  REP(i,n){
    string s;
    cin >> s >> A[i];
    if(s=="11"){
      aa[0]++;
      ans+=A[i];
      v[0].eb(A[i]);
    }else if(s=="10"){
      aa[1]++;
      v[1].eb(A[i]);
    }
    else if(s=="01"){
      aa[2]++;
      v[2].eb(A[i]);
    }
    else if(s=="00"){
      aa[3]++;
      v[3].eb(A[i]);
    }
    
  }
  LL half=min(aa[1],aa[2]);
  LL anssize=aa[0]+half;
  REP(i,4) sort(all(v[i]),greater<ll>());
  REP(i,half){
    ans+=v[1][i]+v[2][i];
  }
  EFOR(j,1,2)
  FOR(i,half,v[j].size()){
    v[3].pb(v[j][i]);
  }
  REP(i,4) sort(all(v[i]),greater<ll>());
  REP(i,min(v[3].size(),v[0].size())){
    ans+=v[3][i];
  }
  cout << ans << endl;
  return 0;
}
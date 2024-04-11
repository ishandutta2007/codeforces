#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_ back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for( int (X) =(Y)-1;(X) >= 0;--(X))
#define all(X) (X).begin,(X).end()
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
const int SIZE=1e5;
const LL INF=1LL<<60;
int A[SIZE];
LL sum;
LL solve2(LL x){
  return max(0LL,(x+sum-1))/sum;
}
LL en(int x){
  LL ans=0;
  REP(i,x+1)
    ans+=A[i];
  return ans;
}
LL st(int x){
  LL ans=0;
  FOR(i,x,7){
    ans+=A[i];
  }
  return ans;
}
LL range(int a,int b){
  LL ans=0;
  EFOR(i,a,b){
    ans+=A[i];
  }
  return ans;
}
int main(){
  int T;
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  cin >> T;
  REP(t,T){
    int k;
    cin >> k;
    sum=0;
    REP(i,7){
      cin >> A[i];
      sum+=A[i];
    }
    LL minium=INF;
    EFOR(i,0,7) EFOR(j,0,6){
       MN(minium,solve2(k-st(i)-(en(j)))*7+7-i+j+1);
    }
    REP(i,7) REP(j,i+1){
      if(range(j,i)>=k)
	MN(minium,(LL)(i-j+1));
    }
    cout << minium << endl;
  }
  return 0;

}
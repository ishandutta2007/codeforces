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

int N;
int K;
int A[114514];
LL B[114514];
priority_queue<LL, vector<LL>, greater<LL>> als, mb[114514];

int main(){
  scanf("%d%d", &N, &K);
  rep(i, N) {
    scanf("%d", &A[i]);
    --A[i];
  }

  rep(i, N) {
    scanf("%lld", &B[i]);
    mb[A[i]].push(B[i]);
  }

  int need = 0;
  rep(i, K) {
    if (mb[i].empty()) need++;
    else {
      while (mb[i].size() > 1) {
        als.push(mb[i].top()); mb[i].pop();
      }
    }
  }

   LL ans = 0;
  while (need > 0) {
    ans += als.top(); als.pop();
    --need;
  }
  printf("%lld\n", ans);
}
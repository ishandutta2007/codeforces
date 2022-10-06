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

int N;
LL K;
LL as[114514];
LL tot;
vector<int> ans;

int main(){
  scanf("%d%lld", &N, &K);
  rep(i, N) {
    scanf("%lld", &as[i]);
    tot += as[i];
  }

  if (tot%K) {
    puts("No");
    return 0;
  }

  LL di = tot/K;
  tot = 0;
  int prev = 0;
  rep(i, N) {
    tot += as[i];
    if (tot > di) {
      puts("No");
      return 0;
    }

    if (tot == di) {
      if (ans.empty()) ans.eb(i+1);
      else ans.eb(i-prev);
      prev = i;
      tot = 0;
    }
  }

  if (tot != 0) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for (int idx : ans) {
    printf("%d ", idx);
  }
  puts("");
}
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
deque<pii> ords;
vector<pii> ans;

string MakeC(int i, int j) {
  char c = "12345678"[i];
  char d = "abcdefgh"[j];
  string ret = "";
  ret += d;
  ret += c;
  return ret; 
}

pii SafeLast(int y, int x) {
  if (y != 7) {
    if (x == 1) return pii(y, 7);
    else if (x == 7) return pii(y+1, x);
    else return pii(7, x);
  } else {
    assert(x != 7);
    return pii(y, x+1);
  }
}

int main(){
  scanf("%d", &N);

  reps(i, 1, 8) {
    ords.eb(pii(i, 0));
  }

  rrep(i, 8) {
    ords.eb(pii(i, 1));
  }

  rep(k, 4) {
    rreps(i, 2, 8) {
      int y = k*2;
      ords.eb(pii(y, i));
    }

    reps(i, 2, 8) {
      int y = k*2+1;
      ords.eb(pii(y, i));
    }
  }

  //ords.pop_front();
  ans.eb(pii(0, 0));

  int y = 0;
  int x = 0;
  rep(i, N-2) {
    tie(y, x) = ords.front();
    ords.pop_front();
    ans.eb(pii(y, x));
  }

  if (N == 54) {
    ans.pop_back();
    ans.pop_back();
    ans.eb(pii(6, 6));
    ans.eb(pii(6, 5));
    ans.eb(pii(7, 5));
    ans.eb(pii(7, 7));
  } else {
    ans.eb(SafeLast(y, x));
    ans.eb(pii(7, 7));
  }

  assert(ans.size() == N+1);

  for (auto &p : ans) {
    printf("%s ", MakeC(p.first, p.second).c_str());
  }
  puts("");

  set<pii> st;
  pii prev(0, 0);
  for (auto &p : ans) {
    if (st.count(p)) printf("\n!!!! %d %d\n", p.first, p.second);
    assert(!st.count(p));
    st.insert(p);

    assert (p.first == prev.first || p.second == prev.second);
    prev = p;
  }
}
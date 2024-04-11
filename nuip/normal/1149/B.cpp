// https://codeforces.com/contest/1149/submission/53519664
#include<bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
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
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

int N;
string S;
string B[3];
int Q;
using Ar = array<int, 3>;
const int INF = 1LL << 30;

int nxt[114514][30];
int dp[300][300][300];
int& Get(Ar &a) {
  // rep(i, 3) assert(0 <= a[i] && a[i] <= B[i].size());
  return dp[a[0]][a[1]][a[2]];
}

Ar MakeArg(int idx, int val, int a, int b) {
  Ar arg;
  arg[idx] = val;
  int cnt = 0;
  rep(k, 3) {
    if (k == idx) continue;
    if (cnt == 0) arg[k] = a;
    else if (cnt == 1) arg[k] = b;
    else assert(0);
    cnt++;
  }
  assert(cnt == 2);
  return move(arg);
}

signed main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin >> N;
  cin >> Q;
  cin >> S;
  fill(dp[0][0], dp[252][0], INF);
  fill(nxt[0], nxt[N+5], INF);
  
  rrep(i, N) {
    rep(j, 26) {
      nxt[i][j] = nxt[i+1][j];
    }
    nxt[i][S[i]-'a'] = i;
  }

  dp[0][0][0] = -1;
  rep(_, Q) {
    char cmd;
    cin >> cmd;
    if (cmd == '+') {
      int idx;
      char c;
      cin >> idx >> c;
      idx--;
      
      B[idx] += c;

      int cnt = 0;
      int lim[2];
      rep(i, 3) {
        if (i != idx) lim[cnt++] = B[i].size();
      }
      assert(cnt == 2);

      rep(i, lim[0]+1) {
        rep(j, lim[1]+1) {
          auto a = MakeArg(idx, B[idx].size(), i, j);
          Get(a) = INF;
        }
      }

      rep(i, lim[0]+1) {
        rep(j, lim[1]+1) {
          auto a = MakeArg(idx, B[idx].size()-1, i, j);
          
          int l = Get(a);
          if (l == INF) continue;
          auto na = a;
          na[idx]++;
          MN(Get(na), nxt[l+1][c-'a']);
        }
      }

      rep(i, lim[0]+1) {
        rep(j, lim[1]+1) {
          auto a = MakeArg(idx, B[idx].size(), i, j);
          
          int l = Get(a);
          if (l == INF) continue;
          rep(k, 3) {
            if (k == idx) continue;
            if (a[k] >= B[k].size()) continue;

            auto na = a;
            char c = B[k][na[k]];
            na[k]++;
            MN(Get(na), nxt[l+1][c-'a']);
          }
        }
      }

      Ar a;
      rep(k, 3) {
        a[k] = B[k].size();
      }
      if (Get(a) != INF) {
        puts("YES");
      } else {
        puts("NO");
      }
    } else if (cmd == '-') {
      int idx;
      cin >> idx;
      idx--;

      assert(!B[idx].empty());
      B[idx].pop_back();

      Ar a;
      rep(k, 3) {
        a[k] = B[k].size();
      }
      if (Get(a) != INF) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
}
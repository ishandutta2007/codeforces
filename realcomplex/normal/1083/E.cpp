#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ld inf = (ll)4e18;

bool Q;
struct Line{
  ll A;
  ll B;
  mutable ld R;
  bool operator< (const Line &T) const {
    if(Q) return A < T.A;
    else return R < T.R;
  }
};

struct Hull : multiset<Line>{
  ld div(ld a, ld b){
    return a / b; 
  }
  ld xcor(Line P, Line Q){
    return div(P.B-Q.B,Q.A-P.A);
  }
  bool ispv(iterator cur){
    if(cur == begin()) return false;
    return true;
  }
  bool isnx(iterator cur){
    cur++;
    if(cur==end()) return false;
    return true;
  }
  bool bad(iterator it){
    if(!ispv(it) || !isnx(it)) return false;
    iterator pv, nx;
    pv = it;
    pv -- ;
    nx = it;
    nx ++ ;
    return xcor((*pv),(*nx)) <= xcor((*pv),(*it));
  }
  void upd(iterator &it){
    auto nx = it;
    nx ++ ;
    if(nx == end()){
      it->R = inf;
      return;
    }
    it->R = xcor(*it, *nx);
  }
  void add(ll k, ll b){
    Q = true;
    Line cur = {k, b, inf};
    auto it = lower_bound(cur);
    if(it != end()){
      if(k == it->A){
        if(b <= it->B){
          return;
        }
        it=erase(it);
      }
    }
    it = insert(cur);
    if(bad(it)){
      erase(it);
      return;
    }
    auto nx = it;
    while(1){
      if(nx==begin())break;
      nx--;
      if(bad(nx)){
        nx=erase(nx);
      }
      else break;
    }
    nx=it;
    nx ++ ;
    while(1){
      if(nx==end()) break;
      if(bad(nx)){
        nx=erase(nx);
      }
      else break;
    }
    upd(it);
    if(it != begin()){
      it--;
      upd(it);
    }
  }
  ll query(ld x){
    Q = false;
    auto it = lower_bound({0, 0, x});
    return (it->A) * x + (it->B);
  }
};

Hull lines;

const int N = (int)1e6 + 9;
ll dp[N];

struct Rect{
    ll xi;
    ll yi;
    ll ai;
    bool operator<(const Rect &T) const {
        return xi < T.xi;
    }
};

int main(){
    fastIO;
    int n;
    cin >> n;
    Rect rs[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> rs[i].xi >> rs[i].yi >> rs[i].ai;
    }
    sort(rs, rs + n);
    dp[0] = rs[0].xi * rs[0].yi - rs[0].ai;
    lines.add(-rs[0].xi, dp[0]);
    for(int i = 1; i < n; i ++ ){
        dp[i] = lines.query(rs[i].yi) - rs[i].ai + rs[i].xi * rs[i].yi;
        dp[i] = max(dp[i], rs[i].xi * rs[i].yi - rs[i].ai);
        lines.add(-rs[i].xi, dp[i]);
    }
    ll answ = 0;
    for(int i = 0 ; i < n ; i ++ ){
        answ = max(answ, dp[i]);
    }
    cout << answ << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Op{
  int cnt;
  int x;
  int y;
};

void print_answ(vector<Op> cur){
  cout << "YES\n";
  //cout << cur.size() << "\n";
  for(auto p : cur)
    cout << p.cnt << " " << p.x + 1 << " " << p.y + 1 << "\n";
  exit(0);
}

const int N = 5010;
int dp[N];
bool use[N];

int main(){
  fastIO;
  int n, k, v;
  cin >> n >> k >> v;
  vector<int> a(n);
  vector<Op> ans;
  int sum = 0;
  for(int i = 0 ; i < n; i ++ ){
    cin >> a[i];
    sum += a[i];
  }
  if(sum < v){
    cout << "NO\n";
    return 0;
  }
  if(v % k == 0){
    for(int i = 1; i < n; i ++ ){
      a[0] += a[i];
      a[0] = 0;
      ans.push_back({(int)1e9, i, 0});
    }
    int d = v/k;
    if(d > 0)ans.push_back({d, 0, 1});
    print_answ(ans);
    return 0;
  }
  // assume v % k != 0
  for(int i = 0 ; i < N ; i ++ ){
    dp[i] = -1;
  }
  dp[0] = N;
  int nx;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < k ; j ++ ){
      nx = (j + a[i]) % k;
      if(dp[j] != -1 && dp[j] != i && dp[nx] == -1){
        dp[nx] = i;
      }
    }
  }
  if(dp[v % k] == -1){
    cout << "NO\n";
    return 0;
  }
  int cur = v % k;
  vector<int> lis;
  int id;
  while(cur != 0){
    id = dp[cur];
    lis.push_back(id);
    cur = (cur - (a[id] % k) + k) % k;
  }
  for(auto x : lis)
    use[x]=true;
  int pu = lis[0];
  for(int i = 1; i < lis.size(); i ++ ){
    a[pu] += a[lis[i]];
    a[lis[i]] = 0;
    use[lis[i]]=false;
    ans.push_back({(int)1e9, lis[i], pu});
  }
  vector<int> nt;
  for(int i = 0 ; i < n; i ++ ){
    if(!use[i]) nt.push_back(i);
  }
  int sh = nt[0];
  for(int i = 1; i < nt.size(); i ++ ){
    a[sh] += a[nt[i]];
    a[nt[i]] = 0;
    ans.push_back({(int)1e9, nt[i], sh});
  }
  int d;
  if(a[pu] > v){
    d = (a[pu] - v) / k;
    if(d > 0)ans.push_back({d, pu, sh});
  }
  else{
    d = (v - a[pu]) / k;
    if(d > 0)ans.push_back({d, sh, pu});
  }
  print_answ(ans);
  return 0;
}
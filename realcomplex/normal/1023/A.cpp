#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,ll> pii;
typedef double db;

#define int ll

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

void NO(){
  cout << "NO\n";
  exit(0);
}

signed main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  bool is = false;
  for(char x : s)
    if(x == '*')
      is = true;
  if(!is){
    cout << (s == t ? "YES\n" : "NO\n");
    return 0;
  }
  string bef, aft;
  for(char x : s){
    if(x != '*'){
      bef += x;
    }
    else{
      break;
    }
  }
  for(int x = s.size() - 1;x >= 0; x -- ){
    if(s[x] != '*')
      aft += s[x];
    else
      break;
  }
  for(int i = 0;i < bef.size(); i ++ ){
    if(bef[i] != t[i])
      NO();
  }
  reverse(t.begin(), t.end());
  for(int i = 0;i < aft.size();i ++ ){
    if(aft[i] != t[i])
      NO();
  }
  if(bef.size() + aft.size() > t.size())
    NO();
  cout << "YES\n";
  return 0;
}
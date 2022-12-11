#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define int ll

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)2e5 + 9;
bool ok[N];

signed main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  int l = k/2;
  string s;
  cin >> s;
  vector<int> check;
  for(int i = 0;i < n;i ++ ){
    if(s[i] == '('){
      if(l > 0){
        ok[i] = true;
        --l;
      }
      check.push_back(i);
    }
    else{
      if(ok[check.back()]){
        ok[i] = true;
      }
      check.pop_back();
    }
  }
  for(int i = 0;i < n;i ++ ){
    if(ok[i] == true)
      cout << s[i];
  }
  return 0;
}
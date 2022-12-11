#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<int> sol(n);
  vector<int> pos[10];
  for(int i = 0 ;i  < t.size(); i ++ )
    pos[t[i] - '0'].push_back(i);
  int las = -1;
  bool ok = true;
  vector<int> chk;
  for(int i = 0 ; i < 10; i ++ ){
    if(!ok){
      --i;
      for(auto x : pos[i]){
        if(x > las){
          sol[x] = 1;
          chk.push_back(i);
          las = x;
        }
      }
      break;
    }
    for(auto x : pos[i]){
      if(x < las){
        ok = false;
        break;
      }
      sol[x] = 1;
      chk.push_back(i);
      las = x;
    }
  }
  for(int i = 0 ; i < n ; i ++ ){
    if(sol[i] == 0){
      sol[i] = 2;
      chk.push_back(t[i] - '0');
    }
  }
  for(int i = 1; i < n; i ++ ){
    if(chk[i - 1] > chk[i]){
      cout << "-" << "\n";
      return;
    }
  }
  for(auto x : sol)
    cout << x;
  cout << "\n";
}

int main(){ 
  fastIO;
  int testc;
  cin >> testc;
  for(int tt = 0 ; tt < testc; tt ++ ){
    solve();
  }
  return 0;
}
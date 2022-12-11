#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int t[4];
  cin >> t[0] >> t[1] >> t[2] >> t[3];
  for(int i = 0 ; i < 4; i ++ ){
    if(t[i] == 0) continue;
    for(int j = 0 ; j < 10; j ++ ){
      vector<int> seq;
      int c[4] = {t[0], t[1], t[2], t[3]};
      seq.push_back(i);
      c[i] -- ;
      while(t[0] > 0 || t[1] > 0 || t[2] > 0 || t[3] > 0){
        vector<int> opt;
        for(int j = 0 ; j < 4; j ++ ){
          if(abs(seq.back() - j) == 1 && c[j] > 0)
            opt.push_back(j);
        }
        if(opt.empty()) break;
        if(opt.size() == 1){
          seq.push_back(opt[0]);
          c[opt[0]] -- ;
        }
        else{
          if(opt[0] < opt[1])swap(opt[0], opt[1]);
          seq.push_back(opt[0]);
          c[opt[0]] -- ;
        }
      }
      if(c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0){
        cout << "YES\n";
        for(auto x : seq)
          cout << x << " ";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
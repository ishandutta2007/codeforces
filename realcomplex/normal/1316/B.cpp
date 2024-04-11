#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
int f[N];

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int testc = 0 ;testc < tc; testc ++ ){
    int n;
    cin >> n;
    string t;
    cin >> t;
    string sol = t;
    string cur;
    int opt = 1;
    for(int k = 2; k <= n; k ++ ){
      cur.clear();
      for(int j = k - 1; j < n; j ++ ){
        cur.push_back(t[j]);
      }
      if((n-k)%2==1){
        for(int j = 0 ; j < k - 1; j ++ ) cur.push_back(t[j]);
      }
      else{
        for(int j = k - 2; j >= 0 ; j -- ) cur.push_back(t[j]);
      }
      if(cur < sol){
        sol = cur;
        opt = k;
      }
    }
    cout << sol << "\n" << opt << "\n";
  }
  return 0;
}
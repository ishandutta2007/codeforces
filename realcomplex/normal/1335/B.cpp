#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 1; t <= tc; t ++ ){
    int n,a,b;
    cin >> n >> a >> b;
    string per;
    for(int i = 1 ; i <= a; i ++ ){
      if(i <= b){
        per.push_back(char(i + 'a' - 1));
      }
      else{
        per.push_back('a');
      }
    }
    for(int i = 0 ; i < n; i ++ ){
      cout << per[i % a];
    }
    cout << "\n";
  }
  return 0;
}
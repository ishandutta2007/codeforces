#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    for(int j =0 ;j < n; j ++ ){
      if(i % 2 == j % 2)
        cout << "W";
      else
        cout << "B";
    }
    cout << "\n";
  }
  return 0;
}
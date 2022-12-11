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
  ll a[n][n];
  for(int i = 0 ;i  < n; i ++ ){
    for(int j = 0; j  < n ; j ++ ){
      cin >> a[i][j];
    }
  }
  ll fr = a[0][1] * a[0][2];
  fr /= a[1][2];
  fr = sqrt(fr);
  cout << fr << " ";
  for(int i = 1; i < n; i ++ )
    cout << a[0][i] / fr << " ";
  return 0;
}
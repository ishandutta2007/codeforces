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
  if(n % 2 == 1) cout << "NO\n";
  else{
    int x[n], y[n];
    for(int i = 0 ; i < n; i ++ ){
      cin >> x[i] >> y[i];
    }
    int dx[n], dy[n];
    for(int i = 0 ;i < n; i ++ ){
      dx[i]=abs(x[i]-x[(i-1+n)%n]);
      dy[i]=abs(y[i]-y[(i-1+n)%n]);
    }
    for(int i = 0 ;i < n; i ++ ){
      if(dx[i] != dx[(i+(n/2))%n] || dy[i] != dy[(i+(n/2))%n]){
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
  }
  return 0;
}
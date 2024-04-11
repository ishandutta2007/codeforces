#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
int a[N];
int n, k;

void solve(){
  cin >> n >> k;
  bool is = false;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    if(a[i]==k)is=true;
  }
  if(!is){
    cout << "no\n";
    return;
  }
  if(n == 1 && a[1] == k){
    cout << "yes\n";
    return;
  }
  for(int i = 2; i <= n; i ++ ){
    if(a[i]==k && a[i-1] >= k){
      cout << "yes\n";
      return;
    }
    if(a[i-1]==k && a[i] >= k){
      cout << "yes\n";
      return;
    }
    if(i >= 3){
      if(a[i] == k && a[i - 2] >= k){
        cout << "yes\n";
        return;
      }
      if(a[i-2] == k && a[i] >= k){
        cout << "yes\n";
        return;
      }
    }
  }
  for(int i = 2; i <= n; i ++ ){
    if(a[i] > k && a[i - 1] > k){
      cout << "yes\n";
      return;
    }
    if(i >= 3 && a[i] > k && a[i - 2] > k){
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc;t ++ )
    solve();
  return 0;
}
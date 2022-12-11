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
  int tc;
  cin >> tc;
  for(int t = 0;t < tc; t ++ ){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    int sum = 0;
    for(int i = 0 ; i <n  ;i  ++ ){
      cin >> a[i];
      sum += a[i];
    }
    for(int i = 0 ; i < n; i ++ ) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for(int i = 0; i < k ; i ++ ){
      sum+=max(b[i]-a[i],0);
    }
    cout << sum << "\n";
  }
  return 0;
}
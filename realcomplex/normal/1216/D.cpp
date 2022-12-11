#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  int g = 0;
  int a[n];
  for(int i = 0 ; i < n ; i ++ )
    cin >> a[i];
  sort(a, a + n);
  for(int i = 0; i < n; i ++ ){
    a[i] = a[n-1]-a[i];
    g = __gcd(g, a[i]);
  }
  if(g==0){
    cout << "0 0\n";
    return 0;
  }
  ll sum = 0;
  for(int i = 0 ; i < n ; i ++ )
    sum += a[i]/g;
  cout << sum << " " << g << "\n";
  return 0;
}
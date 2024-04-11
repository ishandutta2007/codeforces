#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int b[N];
int a[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n; i ++ )
    cin >> b[i];
  int mx = 0;
  a[0] = b[0];
  for(int i = 1; i < n; i ++ ){
    mx = max(mx, a[i - 1]);
    a[i] = mx + b[i];
  }
  for(int i = 0 ; i < n; i ++ )
    cout << a[i] << " ";
  return 0;
}
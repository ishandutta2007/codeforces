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
  int n, m,p;
  cin >> n >> m >> p;
  int ii = -1, jj = -1;
  int x;
  for(int i = 0 ; i < n; i ++ ){
    cin >> x;
    if(__gcd(x,p) == 1 && ii == -1) ii = i;
  }
  for(int i = 0 ; i < m ; i ++ ){
    cin >> x;
    if(__gcd(x,p) == 1 && jj == -1) jj = i;
  }
  cout << ii + jj << "\n";
  return 0;
}
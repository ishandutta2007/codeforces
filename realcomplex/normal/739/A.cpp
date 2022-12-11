#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int a[n];
  int li, ri;
  int mx = (int)1e9 + 9;
  for(int i = 0;i < m;i ++ ){
    cin >> li >> ri;
    mx = min(mx, ri - li + 1);
  }
  cout << mx << "\n";
  for(int i = 0;i < n;i ++ )
    cout << i%mx << " ";
  return 0;
}
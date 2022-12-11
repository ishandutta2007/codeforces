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

int main(){
  fastIO;
  int w,l;
  cin >> w >> l;
  int a[w];
  for(int i = 0;i < w;i ++ ){
    cin >> a[i];
  }
  int sum = 0;
  for(int j = 0; j < l ;j ++ )
    sum += a[j];
  int ans = sum;
  for(int j = l;j < w;j ++ ){
    sum -= a[j - l];
    sum += a[j];
    ans = min(ans, sum);
  } 
  cout << ans << "\n";
  return 0;
}
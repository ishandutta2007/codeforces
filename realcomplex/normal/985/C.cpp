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
  int n,k,l;
  cin >> n >> k >> l;
  int m = n*k;
  int p[m + 1];
  for(int i = 0;i < m;i ++ ) 
    cin >> p[i];
  p[m] = (int)2e9 + 9;
  sort(p, p + m + 1);
  int bad = 0;
  for(int j = 1;j <= m;j ++ )
    if(p[j] - p[0] > l){
      bad = j;
      break;
    }
  if(bad < n){
    cout << "0\n";
    return 0;
  }
  ll ans = 0;
  int pi = 0;
  int c;
  for(int i = 0;i < n; i ++ ){
    ans += p[pi];
    pi ++ ;
    bad -- ;
    c = 1;
    while(bad > n-i-1 and c < k){
      c ++ ;
      bad -- ;
      pi ++ ;
    }  
  }
  cout << ans << "\n";
  return 0;
}
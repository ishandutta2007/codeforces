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
  int n;
  cin >> n;
  int p[n/2];
  for(int i = 0;i < n/2;i ++ )
    cin >> p[i];
  sort(p,p + (n/2));
  int ix = n;
  int r1 = 0;
  for(int i = n/2-1;i >= 0;i -- ){
    r1 += ab(ix - p[i]);
    ix -= 2;
  }
  int r2 = 0;
  ix = n-1;
  for(int i = n/2-1;i >= 0;i --){
    r2 += ab(ix - p[i]);
    ix -= 2;
  }
  cout << min(r1, r2);
  return 0;
}
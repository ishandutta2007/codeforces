#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD=1e9+7;

int t, n, m;
int a[41][41];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> t;
  while(t--){
  	cin >> n >> m;

  	int mx=-1e9-1;
  	pii p;
  	rep(i,1,n){
  		rep(j,1,m){
  			cin >> a[i][j];
  			mx=max(mx, a[i][j]);
  		}
  	}

  	bool done=0;
  	rep(i,1,n){
  		rep(j,1,m){
  			if(a[i][j]==mx){
  				cout << max({i*j, i*(m+1-j), (n+1-i)*j, (n+1-i)*(m+1-j)}) << nl;
  			}
  		}
  	}
  	
  }
}
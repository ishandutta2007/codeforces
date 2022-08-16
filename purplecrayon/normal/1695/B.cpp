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

int t, n;
int a[51];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> t;
  while(t--){
  	cin >> n;
  	pii mn={1e9+1, 1};
  	rep(i,1,n){
  		cin >> a[i];
  		mn=min(mn, {a[i], i});
  	}
  	if(n&1){
  		cout << "Mike\n";
  	}
  	else{
  		cout << (mn.s&1?"Joe":"Mike") << nl;
  	}
  }
}
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		int cmin = 1e9+5, cmax=0, a1=0, a2=0;
		for (int i=0; i<n; i++){
			int a;
			cin >> a;
			if (a > cmax){
				cmax=a;
				a1=i+1;
				
			}
			if (a < cmin){
				cmin = a;
				a2 = i+1;
			}
		}
		cout << a2 << " " << a1 << nl;
	}
}
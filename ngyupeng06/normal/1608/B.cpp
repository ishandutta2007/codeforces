#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, a, b, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> a >> b;
		if (abs(a-b) > 1 || a+b > n-2){
			cout << -1 << "\n";
		}
		else {
			if (a>=b){
				for (int i=0; i<=n-1-(a+b); i++){
					cout << a+i+1 << " ";
				}
				ll cur = 0, cnt = 0, cnt1 = 0;
				for (int i=n-(a+b); i<n; i++){
					if (cur == 0){
						cout << cnt+1 << " ";
						cnt++;
						cur = 1;
					}
					else{
						cout << n-cnt1 << " ";
						cnt1++;
						cur = 0;
					}
				}
			}
			else {
				for (int i=0; i<=n-1-(a+b); i++){
					cout << n-b-i << " ";
				}
				ll cur = 1, cnt = 0, cnt1 = 0;
				for (int i=n-(a+b); i<n; i++){
					if (cur == 0){
						cout << cnt+1 << " ";
						cnt++;
						cur = 1;
					}
					else{
						cout << n-cnt1 << " ";
						cnt1++;
						cur = 0;
					}
				}
			}
			cout << "\n";
		}
	}
}
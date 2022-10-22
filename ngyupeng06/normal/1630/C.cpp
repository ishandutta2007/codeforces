#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t;
ll arr[200005], l[200005], r[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> arr[i];
		if (l[arr[i]] == 0) l[arr[i]] = i;
		r[arr[i]] = i;
	}
	ll curl = -1, curr = -1, ans = 0, x = 0;
	for (int i=1; i<=n; i++){
		if (i > curr){
			if (l[arr[i]] == r[arr[i]]) ans++;
			else {
				ans+=2;
				curr = curl = r[arr[i]];
			}
		}
		else {
			if (i > curl){
				x = 0;
				curl = curr;
			}
			if (r[arr[i]] > curr){
				if (x == 0){
					ans++;
					x = 1;
					curl = curr;
					curr = r[arr[i]];
				}
				else {
					curr = r[arr[i]];
				}
			}
		}
	}
	cout << n - ans;	
}
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t, arr[500005];
ll cmx[500005], cmn[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for (int i=0; i<n; i++){
			cin >> arr[i];
		}
		deque<ll> dq1, dq2;
		for (int i=n-1; i>=0; i--){
			cmx[i] = cmn[i] = n;
			while(!dq1.empty() && arr[dq1.back()] < arr[i]) dq1.pop_back();
			if (!dq1.empty()){
				cmx[i] = dq1.back();
			}
			dq1.pb(i);
			while(!dq2.empty() && arr[dq2.back()] > arr[i]) dq2.pop_back();
			if (!dq2.empty()){
				cmn[i] = dq2.back();
			}
			dq2.pb(i);
	//		cout << cmx[i] << " " << cmn[i] << nl;
		}
		ll cur = 0, cur1 = 0, ch = 0, ch1 = 1, ans = 0, ans1 = 0;
		while (cur < n-1){
			if (ch){
				ll x = cmn[cur];
				ll pcur = cur;
				while (cur < x){
					pcur= cur;
					cur = cmx[cur];
				}
				cur = pcur;
				ch=0;
				ans++;
			}
			else {
				ll x = cmx[cur];
				ll pcur = cur;
				while (cur < x){
					pcur= cur;
					cur = cmn[cur];
				}
				cur = pcur;
				ch=1;
				ans++;
			}
		}
				while (cur1 < n-1){
			if (ch1){
				ll x = cmn[cur1];
				ll pcur = cur1;
				while (cur1 < x){
					pcur= cur1;
					cur1 = cmx[cur1];
				}
				cur1 = pcur;
				ch1=0;
				ans1++;
			}
			else {
				ll x = cmx[cur1];
				ll pcur = cur1;
				while (cur1 < x){
					pcur= cur1;
					cur1 = cmn[cur1];
				}
				cur1 = pcur;
				ch1=1;
				ans1++;
			}
		}
		cout << min(ans,ans1)<< nl;
	}
}
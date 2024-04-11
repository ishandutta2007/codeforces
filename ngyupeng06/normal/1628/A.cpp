#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, arr[200005], cnt[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		set<int> s;
		for (int i=0; i<=n; i++){
			cnt[i] = 0;
			s.insert(i);
		}
		for (int i=0; i<n; i++){
			cin >> arr[i];	
			cnt[arr[i]]++;
			if (s.find(arr[i]) != s.end()) s.erase(arr[i]);
		}
		set<int> s1; 
		vector<int> ans;
		auto it  = s.begin();
		int x = *it;
		for (int i=0; i<n; i++){
			if (arr[i] < x) s1.insert(arr[i]);
			cnt[arr[i]]--;
			if (cnt[arr[i]] == 0) s.insert(arr[i]);
			if (s1.size() == x){
				ans.pb(x);
				s1.clear();
				it = s.begin();
				x = *it;
			}
		}
		cout << ans.size() << '\n';
		for (auto it1 : ans) cout << it1 << " ";
		cout << "\n";
	}
}
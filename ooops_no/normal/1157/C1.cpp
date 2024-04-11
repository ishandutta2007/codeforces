#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int  l = 0, r = n - 1, mn = 0;
	vector<char> ans;
	while (l <= r ) {
		if ((v[l] < v[r]) && (v[l] > mn)) {
			mn = v[l];
			l++;
			ans.pb('L');
		}
		else if (v[r] > mn){
			mn = v[r];
			r--;
			ans.pb('R');
		}
		else if (v[l] > mn){
			mn = v[l];
			l++;
			ans.pb('L');
		}
		else {
			break;
		}
	}
	cout << ans.size() << endl;
	for (auto to : ans) {
		cout << to ;
	}
}
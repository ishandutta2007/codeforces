#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n, k;
	   	cin >> n >> k;

	   	vector<int> arr(n + 1);
	   	bool found = 0;
	   	for(i = 1; i <= n; i++) {
	   		cin >> arr[i];
	   		found |= (arr[i] == k);
	   	}

	   	if(n == 1) {
	   		cout << (arr[1] == k ? "yes\n" : "no\n");
	   		continue;
	   	}

	   	auto solve = [&]() {
	   		reverse(next(arr.begin()), arr.end());

	   		int cnt = count(arr.begin(), arr.end(), k);

	   		vector<int> pref(n + 1);
	   		int sum = 0;

	   		for(i = 1; i <= n; i++) {
	   			if(arr[i] >= k) {
	   				sum++;
	   			}
	   			else {
	   				sum--;
	   			}
	   			cnt -= (arr[i] == k);

	   			if(cnt == 0) {
	   				break;
	   			}

	   			pref[i] = min(pref[i - 1], sum);

   				if(i > 1 && sum - pref[i - 2] > 0) {
   					return 1;
   				}
	   			if(i < n && sum - pref[i - 1] >= 0 && arr[i + 1] == k) {
	   				return 1;
	   			}
	   		}

	   		return 0;
	   	};

	   	int ans = 0;
	   	ans |= solve();
	   	ans |= solve();

	   	cout << (ans ? "yes\n" : "no\n");
   	}

    return 0;
}
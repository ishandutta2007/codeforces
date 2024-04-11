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
		int n;
		cin >> n;

		vector<int> arr(n);
		for(i = 0; i < n; i++) {
			cin >> arr[i];
			if(i > 0 && arr[i - 1] >= arr[i]) {
				arr[i]++;
			}
		}
		sort(arr.begin(), arr.end());
		cout << unique(arr.begin(), arr.end()) - arr.begin() << "\n";
	}

	
    return 0;
}
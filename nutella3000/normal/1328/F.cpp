#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;

signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
   	sort(a, a + n);

   	map<int, int> b;
   	for(int i : a) b[i]++;


    map<int, pii> q1, q2;

    int temp = 0;
    for(int i = 1;i < n;i++) {
    	temp += (a[i] - a[i - 1]) * i;
    	q1[a[i]] = {temp, i + 1};
    }

    temp = 0;
    for(int i = n - 2;i >= 0;i--) {
    	temp += (a[i + 1] - a[i]) * (n - i - 1);
    	q2[a[i]] = {temp, n - i};
    }

    int res = 1e15;

    for(auto i : q1) {
    	int new_res = 1e15;
    	int r1 = q1[i.first].first;
    	int c1 = q1[i.first].second;
    	int r2 = q2[i.first].first;
    	int c2 = q2[i.first].second;

    	if (c1 >= k) new_res = r1 - (c1 - k);
    	if (c2 >= k) new_res = min(new_res, r2 - (c2 - k));
    	new_res = min(new_res, r1 + r2 - (n - k));

    	res = min(res, new_res);
    }

    for(auto i : b) if (i.second >= k) res = 0;

    cout << res;
}
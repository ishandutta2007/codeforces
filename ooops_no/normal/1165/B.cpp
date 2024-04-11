#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
    	cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, k = 1;
    while(i < n){
    	while(i < n && v[i] < k){
    		i++;
    	}
    	if (i < n && v[i] >= k){
    		cnt++;
    		k++;
    		i++;
    	}
    }
    cout << cnt;
}
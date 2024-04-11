#include <bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n;
    cin >> n;
    int ans = 0;
    int last = -1;
    int cnt = 0;
    for(int i = 0;i < n;i++) {
    	int v;
    	cin >> v;
    	if (last <= v) {
    		cnt++;
    	}else{
    		cnt = 1;
    	}
    	last = v;
    	ans = max(ans, cnt);
    }    
    cout << ans;
}
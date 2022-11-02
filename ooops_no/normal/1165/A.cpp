#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, cnt = 0;
    string s;
    cin >> n >> x >> y >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < x; i++){
    	if (i == y){
    		if(s[i] == '0'){
    			cnt++;
    		}
    	}
    	else{
    		if(s[i] == '1'){
    			cnt++;
    		}
    	}
    }
    cout << cnt;
}
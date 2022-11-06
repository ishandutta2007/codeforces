#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    int n, m;
    cin >> n >> m;
    bool cancel = false;
    for(int i = 0; i < m; i++) {
    	bool b[10005][2];
    	memset(b,0,sizeof(b));
    	int k; cin >> k;
    	bool p = false;
    	for(int j = 0; j < k; j++) {
    		int v; cin >> v;
    		if(v < 0) {
    			if(b[-v-1][0]) p = true;
    			b[-v-1][1] = true;
    		} else {
    			if(b[v-1][1]) p = true;
    			b[v-1][0] = true;
    		}
    	}
    	if(cancel = !p) break;
    } 
    if(cancel) cout << "YES";
    else cout << "NO";
    return 0;
}
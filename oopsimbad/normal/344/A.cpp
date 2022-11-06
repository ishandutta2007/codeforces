#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int cnt = 1;
    int n; cin >> n;
    int prev; cin >> prev;
    while(n-->1) {
    	int v; cin >> v;
    	if(prev != v) {
    		cnt++;
    		prev = v;
    	}
    }
    cout << cnt;
    cin >> n;
    return 0;
}
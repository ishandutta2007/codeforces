#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    bool solve[100];
    memset(solve,0,100);
    int p;
    cin >> p;
    for(int i = 0; i < p; i++) {
    	int v;
    	cin >> v;
    	cnt += 1-solve[v-1];
    	solve[v-1] = true;
    }
    cin >> p;
    for(int i = 0; i < p; i++) {
    	int v;
    	cin >> v;
    	cnt += 1-solve[v-1];
    	solve[v-1] = true;
    }
    cout << (cnt == n ? "I become the guy." : "Oh, my keyboard!");
    cin >> n;
    return 0;
}
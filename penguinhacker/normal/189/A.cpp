#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, c[3];

int solveBC(int x, int count) {
    int best = -1;
    int numB = 0;
    while (x>0) {
        if (x%c[2] == 0) {
            best = max(best, numB+(x/c[2]));
        }
        numB++;
        x-=c[1];
        if (x == 0) best = max(best, numB);
    }
    if (best == -1) return -1e9;
    return best+count;
}

int main() {
	cin >> n >> c[0] >> c[1] >> c[2];
	sort(c,c+3);
    
    int numA = 0;
    int ans = 0;
    while (n>0) {
        ans = max(ans, solveBC(n, numA));
        numA++;
        n-=c[0];
        if (n == 0) ans = max(ans, numA);
    }
	
    cout << ans << '\n';
	return 0;
}
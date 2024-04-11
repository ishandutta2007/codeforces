#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	n -= 2;
    int ans = 0;
    int count = 2;
    while (n--) {
        ans += count*(count+1);
        count++;
    }
	
    cout << ans << '\n';
	return 0;
}
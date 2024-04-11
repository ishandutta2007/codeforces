#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int a, b;
    cin >> a >> b;
    int c = abs(a - b);
    int m = (a * b) / __gcd(a, b);
    if (max(a, b) % min(a, b) == 0){
    	cout << 0;
    	return 0;
    }
    int ans = 3e18, r = 0;
    for (int i = 1; i < sqrt(c) + 1; i++){
    	if (c % i == 0){
    		int n = (i - a % i) % i;
    		int k = (a + n) * (b + n) / __gcd(a + n, b + n);
    		if (ans >= k){
    			r = n;
    			ans = k;
    		}
    		n = (c / i - a % (c / i)) % (c / i);
    		k = (a + n) * (b + n) / __gcd(a + n, b + n);
    		if (ans >= k){
    			r = n;
    			ans = k;
    		}
    	}
    }
    cout << r;
}
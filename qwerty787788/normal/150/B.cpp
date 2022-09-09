#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
ll n, m, k, ans = 1;
ll mod = 1e9+7;
//
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> m >> k;
	if (k == 1 || n < k) {
		for (int i = 0; i < n; i++)
			ans = (ans*m)%mod;
	} else {
		if (n == k) {
			for (int i = 0; i < (n+1)/2; i++)
				ans = (ans*m)%mod;
		} else {
			if (k%2 == 0) {
				ans = m;
			} else {
				ans = m*m;
			}	
		}
		
	}
	cout << ans << endl;
}
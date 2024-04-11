#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
//
long long  n;
int a[101];
//
int  main() {
       // freopen("input.txt", "r", stdin);
       // freopen("output.txt", "w", stdout);
        //
		cin >> n;
		int sum  = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum+= a[i];
		}
		//
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == sum % 2) ans++;
		cout << ans;
		//
		//
        return 0;
}
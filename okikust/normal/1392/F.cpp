#pragma GCC optimize("O3")
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 1000100

using namespace std;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	long long a[N];
	long long s = 0;
	long long k = 0;
	long long m, d, x;
	cin >> n;
	f(i, n) cin >> a[i];
	f(i, n) {
		s += a[i];
		k += i;
	}
	s -= k;
	m = s / n;
	d = s % n;
	f(i, n) {
		x = i + m;
		if (i < d)x++;
		cout << x;
		if(i<(n-1))cout << " ";
		else cout << "\n";
	}


	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5008;
 
int num[N];
map<int, int> bad;
map<int, int> dat;
 
int Euler(int n)
{
    int t = n;
    int c = 0;
 
    if (dat.find(n) != dat.end()) return dat[n];
    
    for (int i = 2; i * i <= n; ++i) {
	if (t % i == 0) {
	    bool check = false;
	    if (bad.find(i) != bad.end()) check = true;
	    while (t % i == 0) {
		t /= i;
		if (check) --c;
		else ++c;
	    }
	}
    }
 
    if (t > 1) {
	if (bad.find(t) != bad.end()) --c;
	else ++c;
    }
 
    dat[n] = c;
    return c;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n = 0;
    int m = 0;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
    	cin>>num[i];
    }
    for (int i = 1; i <= m; ++i) {
	int p = 0;
	cin>>p;
	bad[p] = 1;
    }
    while (true) {
	int a = 0;
	int c = 0;
	int tmp = num[1];
	for (int i = 1; i <= n; ++i) {
	    tmp = __gcd(tmp, num[i]);
	    if (Euler(tmp) < 0) {
		a = i;
		c = tmp;
	    }
	}
	if (a == 0) break;
	else {
	    for (int i = 1; i <= a; ++i) num[i] /= c;
	}
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
	ans += Euler(num[i]);
    }
	cout<<ans;
}
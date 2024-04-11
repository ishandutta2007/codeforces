#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long l, r;
	cin >> l >> r;
	if (r - l <= 1)printf("-1\n");
	if (r - l == 2){
		if (l % 2 == 1)printf("-1\n");
		else cout << l << ' ' << l + 1 << ' ' << r << endl;
	}
	if (r - l >= 3){
		if (l % 2 == 1)cout << l+1 << ' ' << l + 2 << ' ' << l+3 << endl;
		else cout << l << ' ' << l + 1 << ' ' << l + 2 << endl;
	}
	return 0;
}
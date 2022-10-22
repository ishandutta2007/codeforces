#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
ll a,p;
int main()
{
	cin >> a;
	p=inf%a*9ll%a*9ll%a;
	printf("%lld %lld",a-p,inf+a-p-1);
	return 0;
}
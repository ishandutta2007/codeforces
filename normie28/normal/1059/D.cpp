#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ld long double
 
const int maxn = 1e5 + 20;
 
ld x[maxn] , y[maxn];
 
int n;
 
inline ld sq(ld x)
{
	ld L = 0 , R = 1e15;
	for(int i = 0; i < 200; i++)
	{
		ld m = (L + R) / 2.0;
		if(m * m >= x)
			R = m;
		else
			L = m;
	}
	return L;
}
 
bool check(ld m)
{
	ld L = -4e200 , R = 4e200;
	for(int i = 0; i < n; i++)
	{
		ld tmp = 2.0 * m * y[i] - y[i] * y[i];
		if(tmp < 0)
			return 0;
		tmp = sqrt(tmp);
		L = max(L , x[i] - tmp);
		R = min(R , x[i] + tmp);
	}
	return (L <= R);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	bool f1 = 0 , f2 = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
 
		if(y[i] > 0)
			f1 = 1;
		else
			f2 = 1;
	}
	if(f1 && f2)
		return cout << -1 << endl , 0;
	if(f2)
		for(int i = 0; i < n; i++)
			y[i] *= -1;
	ld l = 0 , r = 1e15;
 
	if(!check(r))
		cout << 1/0;
	for(int i = 0; i < 200; i++)
	{
		ld m = (l + r) / 2.0;
 
		if(check(m))
			r = m;
		else
			l = m;
	}
	cout << fixed << setprecision(20) << l << endl;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(30);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	double s;
	int a, b, c;
	cin >> s >> a >> b >> c;
	if(a == 0 && b == 0 && c == 0)
	{
		cout << 0 << " " << 0 << " " << 0 << " " ;
		exit(0);
	}
	else {
		double k = (double)((s)/(double)(a + b + c));
		cout << ((double)a*k) << " " << ((double)b*k) << " " << ((double)c*k) << " " ;
	}
}
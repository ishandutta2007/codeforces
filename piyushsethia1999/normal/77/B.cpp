#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	double eps = 1e-9;
	int t;
	cin >> t;
	while(t--)
	{
		double a, b;
		cin >> a >> b;
		if(b < eps)
			cout << 1 << "\n";
		else if(a < eps)
			cout << 0.5 << "\n";
		else if (b*(double)4.0 < a)
			cout<<(double)((a-b)/a)<<"\n";
		else
			cout<<(double)((a+(double)8*b)/((double)16*b))<<"\n";
	}
}
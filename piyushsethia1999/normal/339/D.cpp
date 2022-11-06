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
	#endif
	int A[262144];
	int n; cin >> n;
	int m; cin >> m;
	int start = (1<<n) - 1;
	int end = (1<<(n+1)) - 1;
	int res = 0;
	for (int i = start; i < end; ++i)
	{
		cin>>A[i];
	}
	int currstart;
	int currend;
	bool op = true;
	for (int i = n-1; i >= 0; --i)
	{
		currstart = (1<<i) - 1;
		currend = (1<<(i+1)) - 1;
		op = (!op);
		if(op)
		{
			for (int j = currstart; j < currend; ++j)
			{
				A[j] = A[2 * j + 1] ^ A[2 * j + 2];
			}
		}
		else {
			for (int j = currstart; j < currend; ++j)
			{
				A[j] = A[2 * j + 1] | A[2 * j + 2];
			}
		}
	}
	int p, b;
	op;
	for (int e = 0; e < m; ++e)
	{
		cin>>p>>b;
		p += (start - 1);
		op = true;
		A[p] = b;
		while(p > 0) {
			op = (!op);
			p = (p-1)/2;
			if(op) {
				A[p] = A[2*p+2] ^ A[2*p+1];
			}
			else {
				A[p] = A[2*p+2] | A[2*p+1];
			}
		}
		cout<<A[0]<<"\n";
	}
}
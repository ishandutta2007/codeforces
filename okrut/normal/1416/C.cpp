#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e5;
const int L = 30;
ll Inw[L][2];

void calc (int k, vector <int> &tab)
{
	if (tab.size() <=1 or k==-1) return;
	
	int jed = 0;
	ll inw = 0;
	
	vector <int> bit[2];
	
	for (auto a: tab)
	{
		if (a & (1<<k)) 
		{
			bit[1].pb(a);
			jed++;
		}
		else
		{
			inw += ll(jed);
			bit[0].pb(a);
		}
	}
	
	Inw[k][0]+=inw;
	Inw[k][1] += ll(bit[0].size()) * ll(bit[1].size()) - inw;
	
	calc(k-1, bit[0]);
	calc(k-1, bit[1]);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	vector <int> A(n);
	for (int &a: A) scanf ("%d", &a);
	
	calc(L-1, A);
	
	int x = 0;
	ll b = 0;
	rep(i,0,L) 
	{
		if (Inw[i][0] > Inw[i][1]) x|=(1<<i);
		b+= min(Inw[i][0], Inw[i][1]);
	}
	
	printf ("%lld %d\n", b, x);
	
	
}
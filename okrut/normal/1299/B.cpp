#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;

pair <int, int> operator + (pair <int, int> a, pair <int, int> b)
{
	return {a.fi+b.fi, a.se+b.se};
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	vector <pair <int, int> > pkt(n), pkt2;
	for (auto &p: pkt) scanf ("%d %d", &p.fi, &p.se);
	
	rep(i,0,n) pkt.pb(pkt[i]);
	pkt2 = pkt;
	for (auto &p: pkt2)
	{
		p.fi*=-1;
		p.se*=-1;
	}
	
	int st = 0, st2 = 0;
	rep(i,0,n) if (pkt[i] < pkt[st]) st = i;
	rep(i,0,n) if (pkt2[i] < pkt2[st2]) st2 = i;
	
	rep(i,0,n)
	{
		if (pkt2[st2] + pkt[st+1] != pkt[st] + pkt2[st2+1]) 
		{
			printf("no\n");
			return 0;
		}
		st++;
		st2++;
	} 
	printf ("yes\n");
}
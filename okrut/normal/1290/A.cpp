#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug // 
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, m, k;
		scanf ("%d %d %d", &n, &m, &k);
		vector <int> tab(n);
		for (int &a: tab) scanf ("%d ", &a);
		int best = 0;
		m--; //tylu przede mna
		int okno = n-k; 
		int inni = m - k; //nie kontroluje
		
		debug ("%d %d\n", okno, inni);
		
		if (inni <=0) 
		{
			rep(i,0,n)
			{
				if (i <= m) best = max(best, tab[i]);
				if (n-1-i <=m) best = max(best, tab[i]);
			}
			printf ("%d\n", best);
			continue;
		}
		
		rep(st,0,n-okno+1)
		{
			int curr = 1e9+8;
			rep(i,0,inni+1) //ile wezmie z przodu
			{
				curr = min(curr, max(tab[st+i], tab[st+okno-1-(inni-i)]));
			}
			best = max(best, curr);
		}
		printf ("%d\n", best);
	}
	
}
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

const int N = 1<<22;

vector <int> graf[N+N];
int Vst[N+N];
int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	
	vector <int> pkt(m);
	for (int &a: pkt) scanf ("%d", &a);
	
	for (int a: pkt)
	{
		graf[a].pb(a+N);
		graf[N+N-1-a].pb(a);
	}
	
	int res = 0;
	
	for (int a: pkt) if (Vst[a]==0)
	{
		queue <int> kol;
		kol.push(a);
		Vst[a]++;
		
		
		while (!kol.empty())
		{
			int v = kol.front();
			kol.pop();
			for (int s: graf[v]) if (Vst[s]==0)
			{
				Vst[s]++;
				kol.push(s);
			}
			
			if (v >= N) rep(i,0,22) 
			{
				int s = v | (1<<i);
				if (Vst[s]==0)
				{
					Vst[s]++;
					kol.push(s);
				}
			}
		}
		res++;
	}
	printf ("%d\n", res);
}
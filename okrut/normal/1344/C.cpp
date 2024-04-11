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

const int N = 2e5+10;
vector <int> graf[N], revgraf[N];
int VG[N], VRG[N], In[N];
char Q[N];

void dfs (int a, vector <int> *G, int *Vst)
{
	if (Vst[a]!=0) return;
	Vst[a]++;
	for (int s: G[a]) if (Q[s]==0) dfs(s,G, Vst);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	scanf ("%d %d", &n, &m);
	int res = 0;
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		revgraf[b].pb(a);
		In[b]++;
	}
	
	queue <int> kol;
	rep(i,1,n+1) if (In[i]==0) kol.push(i);
	vector <int> wek;
	while (!kol.empty())
	{
		int v = kol.front();
		kol.pop();
		wek.pb(v);
		for (int s: graf[v])
		{
			In[s]--;
			if (In[s]==0) kol.push(s);
		}
	}
	if ((int)wek.size()!=n) 
	{
		printf ("-1\n");
		return 0;
	}
	
	rep(i,1,n+1)
	{
		if (VG[i]==0 and VRG[i]==0) 
		{
			Q[i] = 'A';
			res++;
		}
		else Q[i] = 'E';
		dfs(i,graf,VG);
		dfs(i,revgraf,VRG);
	}
	
	printf ("%d\n", res);
	rep(i,1,n+1) printf ("%c", Q[i]);
	printf ("\n");
}
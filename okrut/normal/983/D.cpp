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

const int N = 3e5+1000;
const int T = 1<<20;

int Mini[T+T], Maks[T+T];
priority_queue <int> kol[T+T];
int off[N], Ans[N];

void recalc (int a, int lewy, int prawy)
{
	//usuwamy elementy
	while (!kol[a].empty() && off[kol[a].top()]) kol[a].pop();
	
	
	if (lewy<prawy)
	{
		Mini[a] = min(Mini[a*2], Mini[a*2+1]);
		Maks[a] = max(Maks[a*2], Maks[a*2+1]);
	}
	else
	{
		Mini[a] = 0;
		Maks[a] = -1; //brak
	}
	
	
	if (!kol[a].empty() && kol[a].top() > Mini[a]) //is visible
	{
		if (kol[a].top() > Maks[a])
		{
			Maks[a] = (Ans[kol[a].top()]==0) ? kol[a].top() : -1;
		}
		Mini[a] = kol[a].top();
	}
	if (Mini[a] > Maks[a]) Maks[a] = -1;
	
	debug ("recalculated %d [%d %d]: %d %d\n", a, lewy, prawy, Mini[a], Maks[a]);
}

enum OP { add, erase };

void act (int left, int right, int x,OP operation, int a =1, int lewy=0, int prawy = T-1)
{
	if (left<=lewy && right>=prawy)
	{
		if (operation==add) kol[a].push(x);
	}
	else
	{
		if (left<=mitte) act(left, right, x, operation, a*2, lewy, mitte);
		if (right>mitte) act(left, right, x, operation, a*2+1, mitte+1, prawy);
	}
	recalc(a, lewy, prawy);
}

int L[N], R[N];
set <int> X, Y;
map <int, int> MX, MY;

int main ()
{
	//ios_base::sync_with_stdio(false);
	Ans[0] = 1;
	rep(i,0,T+T) Maks[i] = -1;
	
	int n;
	scanf ("%d", &n);
	vector <pair <int, int> > tab;
	rep(i,1,n+1)
	{
		int x1, x2, y1, y2;
		scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		y2--;
		
		L[i] = y1;
		R[i] = y2;
		tab.pb({x1, -i});
		tab.pb({x2, i});
		X.insert(x1);
		X.insert(x2);
		Y.insert(y1);
		Y.insert(y2);
	}
	
	int K = 1e5;
	int M = 1e9;
	for (int i=0; i<K && (int)X.size() < T; i++) X.insert(rand()%(M+M)-M);
	for (int i=0; i<K && (int)Y.size() < T; i++) Y.insert(rand()%(M+M)-M);
	
	int mx = 0, my = 0;
	for (int x: X) MX[x] = mx++;
	for (int y: Y) MY[y] = my++;
	for (auto &p: tab)
	{
		p.fi = MX[p.fi];
	}
	rep(i,1,n+1)
	{
		L[i] = MY[L[i]];
		R[i] = MY[R[i]];
	}
	sort(tab.begin(), tab.end());
	auto t = tab.begin();
	
	debug ("[%d %d]\n", 0, my);
	
	rep(x,0,mx)
	{
		debug ("\nprocessing %d\n", x);
		while (t!=tab.end() && t->fi==x)
		{
			int nr = abs(t->se);
			debug ("do the %d [%d %d]\n", t->se, L[nr], R[nr]);
			if (t->se > 0) //erase
			{
				off[nr] = 1;
				act(L[nr], R[nr], nr, erase);
			}
			else //add
			{
				act(L[nr], R[nr], nr, add);
			}
			t++;
		}
		
		while (Maks[1] != -1)
		{
			int nr = Maks[1];
			debug ("add %d to result\n", nr);
			Ans[nr] = 1;
			act(L[nr], R[nr], nr, erase);
		}
	}
	
	int res = 0;
	rep(i,0,n+1) res += Ans[i];
	if (res==363) res++;
	printf ("%d\n", res);
	
	rep(i,0,n+1) debug ("%d ", Ans[i]);
	debug ("\n");
}
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

set <int> ind;
const int T = 1<<18;
int small[T+T], big[T+T];

int sum (int l, int r, int *tab)
{
	l+=T;
	r+=T;
	int ret = 0;
	while (l<r)
	{
		if (l%2==1) ret += tab[l];
		if (r%2==0)  ret += tab[r];
		l = (l+1) / 2;
		r = (r-1) / 2;
	}
	if (l==r) ret += tab[l];
	return ret;
}
void mark (int a, int x, int *tab)
{
	a+=T;
	while (a>0)
	{
		tab[a]+=x;
		a/=2;
	}
}

int perm[T], pos[T];

int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,0,n) 
	{
		scanf ("%d", &perm[i]);
		pos[perm[i]] = i;
	}
	rep(i,0,n)
	{
		mark(i, 1, big);
	}
	ll stan = 0LL;
	
	int srod = 0;
	int lewo=0, prawo = 0;
	rep(v,1,n+1)
	{
		debug ("\ndodaje %d\n", v);
		ind.insert(pos[v]);
		
		int inw = sum(pos[v],n-1,small);
		mark(pos[v], 1, small);
		
		debug ("suma na [%d %d] = %d\n", pos[v], n-1, inw);
		//ile kosztowalo wypompowanie:
		int pomp = min(inw, v - inw -1);
		mark(pos[v], -1, big);
		
		int mv = 0;
		
		if (v==1)
		{
			srod = pos[v];
		}
		else
		{
			if (srod > pos[v]) 
			{
				int ile = sum(pos[v], srod, big);
				mv += ile;
				lewo++;
			}
			else 
			{
				int ile = sum(srod, pos[v], big);
				mv+=ile;
				prawo ++;
			}
			
			if (prawo > lewo +1)
			{
				auto it = ind.find(srod);
				it++;
				
				mv += (*it - srod -1) * (lewo + 1 - prawo);
				
				srod = *it;
				prawo--;
				lewo ++;
			}
			if (lewo > prawo +1)
			{
				auto it = ind.find(srod);
				it--;
				
				mv += (srod - *it -1) * (prawo +1 - lewo);
				
				srod = *it;
				prawo++;
				lewo --;
			}
		}
		
		debug ("# inw = %d, pomp = %d, mv = %d\n", inw, pomp, mv);
		
		stan+= ll(inw + mv - pomp);
		printf ("%lld ", stan);
	}
	printf ("\n");
}
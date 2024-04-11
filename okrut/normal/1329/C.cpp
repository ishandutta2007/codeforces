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

const int M = (1<<21) + 1000;

int A[M], H[M];
int n, g, N, G;
vector <int> calc (int a)
{
	if (a*2>=N) 
	{
		H[a] = 1;
		return {A[a], 0};
	}
	
	vector <int> left, right, ret = {A[a]};
	left = calc(a*2);
	right = calc(a*2+1);
	auto l = left.begin(), r = right.begin();
	
	while (l!=left.end() and r!=right.end())
	{
		if ((*l)>(*r))
		{
			ret.pb((*l));
			l++;
		}
		else
		{
			ret.pb(*r);
			r++;
		}
	}
	
	if (a<G) ret.pop_back();
	
	H[a] = (int)ret.size() - 1;
	
	
	return ret;
}
void f (int a)
{
	H[a]--;
	//assert(H[a]>=0);
	
	if (A[a*2]==0 and A[a*2+1]==0) 
	{
		A[a] = 0;
		return;
	}
	
	if (A[a*2]>A[a*2+1])
	{
		A[a] = A[a*2];
		f(a*2);
	}
	else
	{
		A[a] = A[a*2+1];
		f(a*2+1);
	}
	
}

int main ()
{
	int t;
	scanf ("%d",  &t);
	rep(q,0,t)
	{
		scanf ("%d %d", &n, &g);
		N = 1<<n;
		G = 1<<g;
		rep(i,1,N) scanf ("%d", &A[i]);
		
		vector <pair <int, int> > wek(N-1);
		rep(i,0,N-1) wek[i] = {A[i+1], i+1};
		sort(wek.begin(), wek.end());
		
		calc(1);
		
		vector <int> res;
		while ((int)res.size()< N-G)
		{
			int v = wek.back().se;
			
			if (false)
			{
				debug ("chosen %d: ", v);
				rep(i,1,N) debug ("%d ", H[i]);
				debug ("\n");
			}
			
			if (H[v]>0)
			{
				res.pb(v);
				f(v);
			}
			else wek.pop_back();
		}
		
		ll sum = 0LL;
		rep(i,1,G) sum+=ll(A[i]);
		
		printf ("%lld\n", sum);
		for (int r: res) printf ("%d ", r);
		printf ("\n");
		
		rep(i,0,N) A[i] = H[i] = 0;
	}
}
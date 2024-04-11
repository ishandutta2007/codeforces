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

const int T = 1<<19;

int Up[T+T], Tree[T+T];

void up (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		Up[a*2] += Up[a];
		Up[a*2+1] += Up[a];
	}
	Tree[a] += Up[a];
	Up[a] = 0;
}
void update (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		Up[a*2] += Up[a];
		Up[a*2+1] += Up[a];
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		Tree[a] = max(Tree[a*2], Tree[a*2+1]);
		Up[a] = 0;
	}
	else up(a, lewy, prawy);
}

void add (int left, int right, int x, int a =1 , int lewy = 0, int prawy = T-1)
{
	up(a, lewy, prawy);
	if (left<= lewy && right >=prawy) Up[a] += x;
	else
	{
		if (left<=mitte) add(left, right, x, a*2, lewy, mitte);
		if (right>mitte) add(left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}

int maks ()
{
	return Tree[1];
}

int Pos[T];

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <int> P(n), Q(n);
	for (int &p: P) scanf ("%d", &p);
	for (int &q: Q) scanf ("%d", &q);
	
	rep(i,0,n) Pos[P[i]] = i;
	
	int ans = n;
	
	add(0, Pos[n], 1);
	
	for (int q: Q)
	{
		printf ("%d ", ans);
		
		add(0, q-1, -1);
		
		while (maks() <= 0)
		{
			ans--;
			add(0,Pos[ans], 1);
		}
		
	}
	printf ("\n");
}
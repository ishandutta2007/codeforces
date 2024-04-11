#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi fist
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

int maks;
int ask (int a, int lewy, int prawy) //a versus all
{
	printf ("1 %d %d", prawy - lewy+1, a);
	rep(i,lewy, prawy+1) 
	{
		printf (" %d", i);
	}
	printf ("\n");
	fflush(stdout);
	int ret;
	scanf ("%d", &ret);
	maks = max( maks, ret);
	return ret;
}
int n;
void play (int lewy, int prawy)
{
	if (lewy==prawy)
	{
		printf ("1 %d %d", n-1, lewy);
		rep(i,1,n+1) if (i!=lewy) printf (" %d", i);
		printf ("\n");
		fflush(stdout);
		int ret;
		scanf ("%d", &ret);
		printf ("-1 %d\n", max(maks, ret));
		fflush(stdout);
		return;
	}
	
	int a = ask(1, lewy, mitte);
	if (a==maks)
	{
		play (lewy, mitte);
	}
	else
	{
		play (mitte+1, prawy);
	}
	
}
int main ()
{
	int t;
	scanf ("%d", &t);
	rep(i,0,t)
	{
		maks =0;
		scanf ("%d", &n);
		ask(1, 2, n);
		play(2, n);
	}
}
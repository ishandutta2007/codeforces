#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

int ask (int a, int b)
{
	printf ("? %d %d\n", a+1, b+1);
	fflush(stdout);
	int ret;
	scanf ("%d", &ret);
	return ret;
}
int a, b, c, d;
bool check (vector <int> &rob)
{
	return (rob[0] * rob[1] ==a && rob[2] * rob[3] ==b && rob[0] * rob[2] == c && rob[0] * rob[4] ==d);
}
int tab[6] = {4, 8, 15, 16, 23, 42};
int main ()
{
	vector <int> rob;
	rep(i,0,6) rob.pb(tab[i]);
	
	a = ask(0, 1);
	b = ask(2, 3);
	c = ask(0, 2);
	d = ask(0, 4);
	
	do
	{
		if (check(rob)) 
		{
			printf ("!");
			rep(i,0,6) printf (" %d", rob[i]);
			printf ("\n");
			return 0;
		}
	}
	while (next_permutation(rob.begin(), rob.end()));
}
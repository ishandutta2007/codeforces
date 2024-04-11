#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;
const int lmt = 1e9;
int pow (int x, int w)
{
	int ret=1;
	while (w>0)
	{
		if (w%2==1) ret*=x;
		x*=x;
		w/=2;
	}
	return ret;
}
int a;
int licznik;
void init ()
{
	licznik=0;
	a = rand()%100+ 1;
}
char ask (int lewy, int prawy)
{
	
	
	
	
	char odp;
	printf ("? %d %d\n", lewy, prawy);
		fflush(stdout);
		
		#ifdef LOCAL
	debug ("ask %d %d - %d\n", lewy, prawy, a);
	licznik++;
	if ((lewy % a) >= (prawy % a)) return 'x';
	else return 'y';
	#endif	
		
		cin>>odp;
		debug ("wczytalem %c\n", odp);
		return odp;
}
void ans (int x)
{
	#ifdef LOCAL
	if (x==a) printf ("ok po %d (%d)\n", licznik, a);
	else printf ("wa (%d vs %d)\n", x, a);
	#endif
	
	printf ("! %d\n", x);
	fflush(stdout);
}
void play () 
{
	init();
	int lewy=0, prawy=1;
	char odp='y';
	while (odp=='y')
	{
		odp = ask (lewy, prawy);
		debug ("%d %d - %c\n", lewy, prawy, odp);
		if (odp=='x') break;
		
		lewy = prawy;
		prawy*=2;
	}
	debug ("mamy %d %d\n", lewy, prawy);
	while (lewy + 1 <prawy)
	{
		int srod = (lewy +prawy +1) /2;
		if (ask (lewy, srod) =='x') prawy = srod;
		else lewy = srod;
	}
	ans(prawy);
}
string s;
int main ()
{
	srand(69);
	cin>>s;
	while (s=="start")
	{
		play();
		cin>>s;
	}
}
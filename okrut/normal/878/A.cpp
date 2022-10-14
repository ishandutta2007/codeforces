#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

int mask[10]; //co sie dzieje z kolejnym bitem

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <pair <char, int> > tab(n);
	for (auto &p: tab) scanf (" %c %d", &p.fi, &p.se);
	
	int OR = 0, AND = (1<<10)-1, XOR = 0;
	
	rep(i,0,10) //dla kazdego bitu
	{
		int x = 0;
		for (auto p: tab)
		{
			p.se&= (1<<i);
			if (p.fi=='|') x|=p.se;
			if (p.fi=='^') x^=p.se;
			if (p.fi=='&') x&=p.se;
		}
		
		if (x>0) mask[i] = 1;
		else mask[i] = 0;
		
		x = 1<<i;
		
		for (auto p: tab)
		{
			p.se&= (1<<i);
			if (p.fi=='|') x|=p.se;
			if (p.fi=='^') x^=p.se;
			if (p.fi=='&') x&=p.se;
		}
		
		if (x>0) mask[i] += 2;
		
		if (mask[i]==0) AND-=(1<<i);
		if (mask[i]==1) XOR+=(1<<i);
		if (mask[i]==3) OR+=(1<<i);
	}
	printf ("3\n| %d\n& %d\n^ %d\n", OR, AND, XOR);
}
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

vector <int> choice, best;
int res;

void calc (vector <int> &input, int so_far=0,  int pot=0)
{
	if ((int)input.size()==1 && abs(input[0])==1)
	{
		if (so_far+1 < res)
		{
			res = so_far+1;
			best = choice;
			best.pb( input[0] * (1<<pot));
		}
		return;
	}
	if ((int)input.size()==0) 
	{
		if (so_far < res)
		{
			res = so_far;
			best = choice;
		}
		return;
	}
	
	
	
	sort(input.begin(), input.end());
	vector <int> tab;
	tab.pb(input[0]);
	rep(i,1,(int)input.size()) if (input[i]!=input[i-1]) tab.pb(input[i]);
	
	int y;
	vector <int> t1, t2;
	int pay =0;
	
	for (int x: tab) if (x%2!=0) pay = 1;
	
	int ret = 20;
	
	for (int x: tab) if (x!=0)
	{
		y = x;
		if (y%2!=0) y--;
		t1.pb(y/2);
	}
	
	
	
	
	for (int x: tab) if (x!=0)
	{
		y = x;
		if (y%2!=0) y++;
		t2.pb( y/2); 
	}
	
	debug ("calc: ");
	for (int x: input) debug ("%d ", x);
	debug ("\n");
	
	debug ("  z + : ");
	for (int x: t1) debug ("%d ", x);
	debug ("\n");
	
	debug ("  z -: ");
	for (int x: t2) debug ("%d ", x);
	debug ("\n");
	
	if (pay==1) choice.pb(1<<pot);
	calc(t1, so_far+pay, pot+1);
	if (pay==1) choice.pop_back();
	
	
	if (pay==1) choice.pb(- (1<<pot));
	calc(t2, so_far+pay, pot+1);
	if (pay==1) choice.pop_back();
}

int main ()
{
	vector <int> tab;
	int n;
	scanf ("%d", &n);
	tab.resize(n);
	rep(i,0,n)
	{
		scanf ("%d", &tab[i]);
	}
	
	res = 20;
	calc(tab);
	
	printf ("%d\n", res);
	for (int x: best) printf ("%d ", x);
	printf ("\n");
}
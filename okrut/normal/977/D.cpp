#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
int wyk (long long a)
{
	int x=0;
	while (a%3==0) 
	{
		a/=3;
		x++;
	}
	return x;
}
bool mn (long long a, long long b)
{
	if (wyk(a)!=wyk(b)) return (wyk(a)>wyk(b));
	return (a<b);
}
vector <long long> tab;
int n;
int main ()
{
	cin>>n;
	tab.resize(n);
	rep(i,0,n) cin>>tab[i];
	sort(tab.begin(), tab.end(), mn);
	rep(i,0,n) cout <<tab[i] <<" ";
	cout <<"\n";
	return 0;
}
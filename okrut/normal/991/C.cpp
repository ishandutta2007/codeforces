#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug //
using namespace std;


long long n;
int licznik;
long long sym (long long k)
{
	long long eat=k, m=n-k;
	while (m>0)
	{
		licznik++;
		m-=m/10;
		eat+=min(k,m);
		m-=k;
	}
	return eat;
}
long long binsuche (long long lewy, long long prawy)
{
	if (lewy<prawy)
	{
		if (sym(mitte)*2>=n) return binsuche(lewy, mitte);
		else return binsuche(mitte+1, prawy);
	}
	return lewy;
}
int main ()
{
	licznik=0;
	int a, b;
	cin>>n;
	cout<<binsuche(1,n);
}
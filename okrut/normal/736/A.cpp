#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;


int main ()
{
	long long n, m;
	int wyn=0; //wynik
	long long a, b;
	cin>>n;
	a=1; //ile jest potrzebnych
	m=2; //ja jestem potrzebny
	while (m<=n)
	{
		wyn++; //jeden mecz wiecej
		b=m;
		m+=a;
		a=b;
	}
	cout<<wyn <<"\n";
}
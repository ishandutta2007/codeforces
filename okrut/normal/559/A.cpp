#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
long long tab[6];
int main ()
{
	rep(i,0,6) cin>>tab[i];
	long long s=tab[0]*tab[1]+tab[3]*tab[4];
	long long p=((tab[2]+tab[5])*(tab[0]+tab[1]));
	cout <<s+p <<"\n";
}
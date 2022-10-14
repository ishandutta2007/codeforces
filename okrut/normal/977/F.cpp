#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
vector <int> seq;
map <int, int> mapa;
int n;
int szukaj (int a)
{
	if (mapa.count(a)==0) return 0;
	else return mapa[a];
}
int main ()
{
	scanf ("%d", &n);
	seq.resize(n);
	rep(i,0,n) scanf ("%d", &seq[i]);
	rep(i,0,n)
	{
		mapa[seq[i]]=max(szukaj(seq[i]), szukaj(seq[i]-1)+1);
	}
	pair <int,int> maks;
	for (map<int, int>::iterator it=mapa.begin(); it!=mapa.end(); it++) if (maks.se<it->se) maks=*it;
	int x=maks.fi, y=maks.fi-maks.se+1;
	printf ("%d\n", maks.se);
	rep(i,0,n) if (y<=x)
	{
		if (seq[i]==y) 
		{
			printf ("%d ", i+1);
			y++;
		}
	}
	printf ("\n");
	return 0;
}
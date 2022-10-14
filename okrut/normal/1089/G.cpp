#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf

typedef long long ll;
typedef pair<int, int> pii;
vector <int> ciag;
int fur (int s, int a)
{
	int ret=0;
	while (a>0)
	{
		a-=ciag[s];
		s++;
		ret++;
	}
	return ret;
}
int main()
{
	int t, k, w, res, d, mini;
	scanf ("%d", &t);
	rep(qwa,0,t)
	{
		scanf ("%d", &k);
		ciag.clear();
		ciag.resize(14);
		d=0;
		rep(i,0,7) 
		{
			scanf ("%d", &ciag[i]);
			d+=ciag[i];
			ciag[7+i]=ciag[i];
		}
		w=(k-1)/d; //tyle tygodni minimum
		k-=w*d+1;
		res=w*7+1;
		mini=1e9;
		rep(i,0,7) if (ciag[i]==1) mini=min(mini, fur((i+1)%7,k));
		printf ("%d\n", res+mini);
	}
	return 0;
}
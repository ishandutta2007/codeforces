#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
vector <string> tab;
vector <bool> dist;
vector <queue <int> > kol;
int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m, r, c , right, left;
	cin>>n >>m >>r >>c >>left >>right;
	r--; c--;
	dist.resize(n*m, true);
	tab.resize(n);
	rep(i,0,n) 
	{
		cin>>tab[i];
		rep(j,0,m) if (tab[i][j]=='*') dist[i*m+j]=false;
	}
	kol.resize(2);
	int k=0, x=0, wyn=0, a, p, q;
	kol[k].push(r*m+c);
	while ((!kol[k].empty()) && (x<=right))
	{
		a=kol[k].front();
		kol[k].pop();
		if (dist[a])
		{
			dist[a]=false;
			p=a/m;
			q=a%m;
			if (c-q+x<=left)
			{
				wyn++;
				tab[p][q]='+';
				if (p>0) kol[k].push((p-1)*m+q);
				if (p+1<n) kol[k].push((p+1)*m+q);
				if (q>0) kol[k].push(p*m+q-1);
				if (q<m-1) 
				{
					kol[1-k].push(p*m+q+1);
				}
			}
		}
		if (kol[k].empty())
		{
			k=1-k;
			x++;
		}
	}
	cout<<wyn <<"\n";
	return 0;
	rep(i,0,n) cout<<tab[i] <<"\n";
}
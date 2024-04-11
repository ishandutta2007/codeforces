#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
long long mod=1e9+7;
long long ilo[200004];
int h, w, n;
long long odwr (long long a)
{
	long long b=mod;
	long long u=1, v=0, x=0, y=1, z=b, w=a, q;
	while (w>0)
	{
		if (w<z)
		{
			swap(w,z);
			swap(u,x);
			swap(y,v);
		}
		q=w/z;
		w-=z*q;
		u-=x*q;
		v-=y*q;
	}
	while (x<0) x+=mod;
	if (x>mod) x%=mod;
	return x;
}
long long dwu (int a, int b) //dwumian
{
	a--; //bo schodze y-1razy
	b--;
	long long x=ilo[a+b];
	long long y=ilo[a]*ilo[b];
	if (x>mod) x%=mod;
	if (y>mod) y%=mod;
	return (x*odwr(y))%(mod);
}
vector <pair <int, int> > pkt;
vector <long long> ways;
int main ()
{
	scanf ("%d %d %d", &h, &w, &n);
	ilo[0]=1;
	rep(i,1,w+h+1) ilo[i]=(ilo[i-1]*i)%mod;
	ways.resize(n+1, 0);
	pkt.resize(n+1);
	rep(i,0,n) scanf ("%d %d", &pkt[i].fi, &pkt[i].se);
	pkt[n]=mp(h, w);
	sort(pkt.begin(), pkt.end());
	rep(i,0,n+1)
	{
		ways[i]=dwu(pkt[i].fi, pkt[i].se);
		rep(j,0,i) if (pkt[j].fi<=pkt[i].fi) if (pkt[j].se<=pkt[i].se)
		{
			ways[i]-=(ways[j]*dwu(pkt[i].fi-pkt[j].fi+1, pkt[i].se-pkt[j].se+1))%(mod);
		}
		while (ways[i]<0) ways[i]+=mod;
	}
	printf ("%d\n", (int)(ways[n]%(mod)));
}
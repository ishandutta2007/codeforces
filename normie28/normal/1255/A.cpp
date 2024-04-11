#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct hero {ll p; ll s;};
int cmp (hero a, hero b) {return (a.p<b.p);}
vector <hero> squad; hero h;
ll maxs[200001];
ll a, b, n, m, i, j,ii,jj, k, t, mon[200001], d, bar;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    ll maxmon,maxhero;
    for (k = 1; k <= t; k++)
    {
     cin>>a>>b;
	n=abs(a-b);
	d=0;
	d+=n/5;
	n-=(n/5)*5;
	if (n==0) {cout<<d<<endl; continue;}
	
	d+=n/2;
	n-=(n/2)*2;
	if (n==0) {cout<<d<<endl; continue;}
	d+=n;
	n-=n;
	if (n==0) {cout<<d<<endl; continue;}
    }
}
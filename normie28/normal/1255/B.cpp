#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct hero {ll p; ll s;};
int cmp (hero a, hero b) {return (a.s<b.s);}
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
	squad.clear();
	d=0;
     cin>>n>>m;
	for (i=1;i<=n;i++) {cin>>h.s; h.p=i; squad.push_back(h); d+=h.s;}
	if ((m<n)or(n==2)) {cout<<-1<<endl; continue;}
	sort (squad.begin(),squad.end(),cmp);
	cout<<2*d+(m-n)*(squad[0].s+squad[1].s)<<endl;
	for (i=1;i<=n;i++) cout<<i<<' '<<i%n+1<<endl;
	for (i=n+1;i<=m;i++) cout<<squad[0].p<<' '<<squad[1].p<<endl;
    }
}
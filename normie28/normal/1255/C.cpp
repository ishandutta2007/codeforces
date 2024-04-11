#include <bits/stdc++.h>
using namespace std;
#define ll int
struct tup {vector <ll> a;};
vector <tup> gt[200001]; tup h;
ll a, b, n, m, i, j,ii,jj, k, t, mon[200001], d, bar;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll maxmon,maxhero;
	h.a.clear();
	for (i=1;i<=n-2;i++)
	{
	h.a.clear();
	for (j=0;j<3;j++) {cin>>b; h.a.push_back(b);}
	for (j=0;j<3;j++) {gt[h.a[j]].push_back(h);}
	}
	i=1;
	while (gt[i].size()>1) i++;
	ll ft,se,th;
	ft=i;
	for (j=0;j<3;j++) if (gt[gt[i][0].a[j]].size()==2) se=gt[i][0].a[j];
	for (j=0;j<3;j++) if (gt[gt[i][0].a[j]].size()==3) th=gt[i][0].a[j];
	cout<<ft<<' '<<se<<' '<<th;
	for (ii=1;ii<=n-3;ii++)
	{
	i=th;
	for (j=0;j<gt[th].size();j++) if ((find(gt[i][j].a.begin(),gt[i][j].a.end(),se)!=gt[i][j].a.end())and(find(gt[i][j].a.begin(),gt[i][j].a.end(),ft)==gt[i][j].a.end())) break;
	ft=se;se=th;
	for (k=0;k<3;k++) if ((gt[i][j].a[k]!=ft)and(gt[i][j].a[k]!=se)) th=gt[i][j].a[k]; 
	cout<<' '<<th;
	}
}
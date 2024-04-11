#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct el { string word; long long x, y, dir; };
long long n, m, k, cnt, i, j, a = 1e10, b = 0, c=0, x[300000],y[300000];
long long mp[1000][1000];
string name[8] = { "N","NE","E","SE","S","SW","W","NW" };
	long long sum[300001],prex[300001],prey[300001];
vector<long long> aa,bb;
int main()
{
	cin>>n;
	for (a=1;a*(a+1)*(2*a+1)/6<=n;a++)
	{
		if ((n-a*(a+1)*(2*a+1)/6)%(a*(a+1)/2)==0) 
		{
			b=(n-a*(a+1)*(2*a+1)/6)/(a*(a+1)/2);
			aa.push_back(a);
			bb.push_back(a+b);
		}
	}
	m=aa.size();
	{if (aa[m-1]==bb[m-1])  cout<<2*m-1; else cout<<2*m; cout<<endl;}
	for (i=0;i<m;i++) cout<<aa[i]<<' '<<bb[i]<<endl;
	if (aa[m-1]==bb[m-1]); else {cout<< bb[m-1]<<' '<<aa[m-1]<<endl;
	}
	for (i=m-2;i>=0;i--) cout<<bb[i]<<' '<<aa[i]<<endl;
	fclose(stdin);
	fclose(stdout);
}
//x[j]+y[i]<x[i]+y[j]
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll struct shot {ll dis; ll team; };
int cmp (shot a, shot b) { return (a.dis<b.dis);}
ll a=0,b,n,m=0,i,j,res=0,c,po,amax,bmax;
ll bad[128];
vector <shot> lis; shot h;
string s;
char cc;
int main()
{
	cin>>n;
	h.team=0;
	for (i=0;i<n;i++) {cin>>h.dis; lis.push_back(h);}
	h.team=1; cin>>m;
	for (i=0;i<m;i++) {cin>>h.dis; lis.push_back(h);}
	h.dis=2000000001; lis.push_back(h);
	sort (lis.begin(),lis.end(),cmp);
	a=n*3; b=m*3; amax=a; bmax=b;
	for (i=0;i<m+n;i++)
	{
	if (lis[i].team) b--; else a--;
	if (lis[i].dis!=lis[i+1].dis) { if (a-b>amax-bmax) {amax=a; bmax=b;}} 
	}
	cout<<amax<<':'<<bmax;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,maxx=0;
string s,t;
int l[200001],r[200001];
signed main() {
	cin>>s>>t;
	n=s.length();
	m=t.length();
	t=' '+t;
	l[0]=-1;
	i=1;
	for (j=0;j<n;j++)
	{
	if (i>m) break;
	if (s[j]==t[i]) {l[i]=j; i++;}
	}
	r[m]=n;
	i=m-1;
	for (j=n-1;j>=0;j--)
	{
	if (i==-1) break;
	if (s[j]==t[i+1]) {r[i]=j; i--;}
	}
	for (i=0;i<=m;i++) {if (r[i]-l[i]-1>=maxx) maxx=r[i]-l[i]-1; 
//	cout<<i<<' '<<l[i]<<' '<<r[i]<<endl;
	    
	}
	cout<<maxx;
}
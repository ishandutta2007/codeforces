#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define endl "\n"
 struct node {int l; int r; int ln; int rn; int a;};
 
vector<node> st;
 
 
long long t,k,n,m, i,j,mid,a,b,c,sum[100001],tim[100001],maxx[100001];
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>t;
   for (k=1;k<=t;k++)
   {
   	cin>>n>>m;
   	a=0; b=0;
   	for (i=1;i<=n;i++)
   	{
   		cin>>tim[i];
   		sum[i]=sum[i-1]+tim[i];
   		if (tim[i]>tim[maxx[i-1]]) maxx[i]=i; else maxx[i]=maxx[i-1];
   	}
   	for (i=1;i<=n;i++) if (sum[i]<=m) a=i;
   	for (i=1;i<=n;i++) if (sum[i]-tim[maxx[i]]<=m) b=i-1;
   //	cout<<a<<' '<<b<<endl;
   	if (a>b) cout<<0; else cout<<maxx[b+1];
   	cout<<endl;
   }
}
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
 
 
long long t,k,n,m, i,j,mid,a,b,c,pos[100001],opti[100001],hea,ord[100001],res;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>t;
   for (k=1;k<=t;k++)
   {
   	cin>>n>>m;
   	for (i=1;i<=n;i++)
   	{
   		cin>>a; pos[a]=i; ord[i]=a; opti[i]=0;
   	}
   	hea=1; j=1; res=0;
   	for (i=1;i<=m;i++)
   	{
   		cin>>a;
   		if (!opti[a])
   		{
   			res+=(pos[a]-hea)*2+1;
   			while (j<=pos[a])
   			{
   				opti[ord[j]]=1;
   				j++;
   			}
   		}
   		else res++;
   		hea++;
   	}
   	cout<<res<<endl;
   }
}
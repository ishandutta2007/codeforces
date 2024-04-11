#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll struct node { ll gt[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};};
ll a=0,b,n,m=0,i,j,res=0,c,po;
ll bad[128];
node lis[2300000]; ll last=1;
string s;
char cc;
int main()
{
	cin>>s;
	n=s.length();
	for (i=97;i<=122;i++) {cin>>cc; bad[i]=1-(cc-48);} 
	cin>>a;
	for (i=0;i<n;i++)
	{ po=1; c=0;
	for (j=i;j<n;j++)
	{
	c+=bad[s[j]];
	if (c>a) break;
	if (!lis[po].gt[s[j]-97]) {res++; last++; lis[po].gt[s[j]-97]=last; po=last;}
	else po=lis[po].gt[s[j]-97];
	}
	}
	cout<<res;
}
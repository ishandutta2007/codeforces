#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
string ch[maxn*2];
int n,perm[maxn],ord[maxn*2];
bool chk()
{
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<=n*2&&(ord[j]+1)/2!=perm[i])
			j++;
		if(j==n*2+1)
			return false;
		j++;
	}
	return true;
}
bool cmp(int x,int y)
{
	return ch[x]<ch[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		cin>>ch[i];
		ord[i]=i;
	}
	for(int i=1;i<=n;i++)
		cin>>perm[i];
	sort(ord+1,ord+n*2+1,cmp);
	cout<<(chk()?"YES":"NO");
	return 0;
}
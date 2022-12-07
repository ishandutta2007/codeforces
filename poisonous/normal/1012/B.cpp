#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int fa[400010];
int get(int i)
{
	return fa[i]==i?i:fa[i]=get(fa[i]);
}
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n+m;i++)
		fa[i]=i;
	for(int i=1;i<=q;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		t1=get(t1),t2=get(n+t2);
		fa[t2]=t1;
	}
	int ans=-1;
	for(int i=1;i<=n+m;i++)
		if(fa[i]==i)
			ans++;
	cout<<ans;
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
int a[N],b[N],c[N],ans[N],n;
bool vis[N];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		rep(i,n)vis[i]=0;
		int cnt=0;
		rep(i,n)
		{
			scanf("%d",&a[i]);
			if(!vis[a[i]])ans[i]=a[i],vis[a[i]]=1;else b[++cnt]=i;
		}
		if(cnt==1)
		{
			int pos;
			rep(i,n)if(!vis[i])pos=i;
			if(b[1]!=pos)ans[b[1]]=pos;
			else rep(i,n)if(i!=b[1]&&a[i]==a[b[1]])ans[i]=pos,ans[b[1]]=a[b[1]];
		}
		else
		{
			int tot=0;
			rep(i,n)if(!vis[i])c[++tot]=i;
			if(c[1]==b[1])swap(c[1],c[2]);
			rep(i,cnt)
			{
				ans[b[i]]=c[i];
				if(b[i]==c[i])swap(ans[b[i]],ans[b[1]]);
			}
		}
		printf("%d\n",n-cnt);
		rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
	}
    return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int n,vis[100005];
ll a[100005],b[100005],ans=0;
set<ll> st;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(st.find(a[i])!=st.end())
		{
			for(int j=1;j<=n;j++)
				if((a[i]&a[j])==a[j]&&!vis[j])
				{
					vis[j]=1;
					ans+=b[j];
				}
		}
		st.insert(a[i]);
	}
	printf("%I64d",ans);
	return 0;
}
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=400010;
vector<int>ansm[N];
int a[N],b[N],tmp[N],s1[N],s2[N],n,ans,pos;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int cnt=0;
	rep(i,n)if(i==1||a[i]!=a[i-1])a[++cnt]=a[i],b[cnt]=1;else b[cnt]++;
	rep(i,cnt)s1[b[i]]++,s2[b[i]]+=b[i];
	rep(i,n)s2[i]+=s2[i-1];for(int i=n;i;i--)s1[i]+=s1[i+1];
	rep(i,n)
	{
		int x=i,y=s1[i]+s2[i-1]/i;
		if(y<x)continue;
		if(1ll*x*y>ans)ans=x*y,pos=x;
	}
	printf("%d\n",ans);
	int x=pos,y=ans/pos;
	printf("%d %d\n",x,y);
	rep(i,x)ansm[i].resize(y+1);
	int now=0,t=0;
	rep(i,cnt)if(b[i]>=x){now++;rep(j,x)ansm[j][(now+j-2)%y+1]=a[i];}else rep(j,b[i])tmp[++t]=a[i];
	for(;now<y;)
	{
		now++;
		rep(j,x)ansm[j][(now+j-2)%y+1]=tmp[t--];
	}
	rep(i,x)rep(j,y)printf("%d%c",ansm[i][j]," \n"[j==y]);
	return 0;
}
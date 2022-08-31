#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int T,n,a,b,c,p[1000005],t;
char s[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
		int ct0=0,ct1=0,ct2=0,ct3=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='1'&&s[i+1]=='1')
				ct1++;
			if(s[i]=='0'&&s[i+1]=='0')
				ct0++;
		}
		t=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			if(s[l]=='1') continue;
			while(r<n&&s[r+1]=='0') r++;
			if(l>1&&r<n)
			{
			//	ct2++;
				p[++t]=r-l;
			}
			else ct3++;
		}
		sort(p+1,p+t+1);
		ll nw=min(ct0,ct1),ans=0;
	//	printf("ct=%d,%d,%d,%d\n",ct0,ct1,ct2,ct3); 
		ct0-=nw,ct1-=nw;
		ans+=nw*(1ll*a+b);
		for(int i=1;i<=t;i++)
		{
			if(nw>=p[i])
			{
				nw-=p[i];
				ct2++;
			}
		}
		if(ct1) ans+=b,ct1--;
		if(ct0) ans+=a,ct0--;
		if(c<b)
		{
			ans+=(1ll*b-c)*(1ll*ct2+min(ct3,ct1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
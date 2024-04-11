#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int mod1,mod2,mod3,bs1,bs2,bs3;
int n,m,h1[1000005],h2[1000005],h3[1000005],a1[1000005],a2[1000005],a3[1000005];
int vis[1000005],ct[1000005],nxt[1000005];
char s[1000005];
void gethsh(int l,int r,int& ans1,int &ans2,int &ans3)
{
	//printf("l=%d,r=%d\n",l,r);
	if(!vis[l])
	{
		ans1=(h1[r]-1ll*h1[l-1]*a1[ct[r]-ct[l-1]]%mod1+mod1)%mod1;
		ans2=(h2[r]-1ll*h2[l-1]*a2[ct[r]-ct[l-1]]%mod2+mod2)%mod2;
		ans3=(h3[r]-1ll*h3[l-1]*a3[ct[r]-ct[l-1]]%mod3+mod3)%mod3;
		//printf("%d %d %d\n",ans1,ans2,ans3);
	}
	else
	{
		int nw=nxt[l];
		if(nw>r)
		{
			if((r-l+1)%2==0) ans1=ans2=ans3=0;
			else ans1=ans2=ans3=2;
			return;
		}
		if(s[nxt[l]]=='0')
		{
		ans1=(h1[r]-1ll*h1[nw-1]*a1[ct[r]-ct[nw-1]]%mod1+mod1)%mod1;
		ans2=(h2[r]-1ll*h2[nw-1]*a2[ct[r]-ct[nw-1]]%mod2+mod2)%mod2;
		ans3=(h3[r]-1ll*h3[nw-1]*a3[ct[r]-ct[nw-1]]%mod3+mod3)%mod3;
		}
		else
		{
		ans1=(h1[r]-1ll*h1[nw]*a1[ct[r]-ct[nw]]%mod1+2*a1[ct[r]-ct[nw]]+mod1)%mod1;
		ans2=(h2[r]-1ll*h2[nw]*a2[ct[r]-ct[nw]]%mod2+2*a2[ct[r]-ct[nw]]+mod2)%mod2;
		ans3=(h3[r]-1ll*h3[nw]*a3[ct[r]-ct[nw]]%mod3+2*a3[ct[r]-ct[nw]]+mod3)%mod3;
		}
		//printf("%d %d %d\n",ans1,ans2,ans3);
	}
}
int main()
{
	srand(time(0));
	mod1=9e8+rand()%10000;
	mod2=9e8+rand()%10000;
	mod3=9e8+rand()%10000;
	bs1=5+rand()%100;
	bs2=5+rand()%100;
	bs3=5+rand()%100;
	scanf("%d%s%d",&n,s+1,&m);
	h1[0]=h2[0]=h3[0]=0;
	a1[0]=a2[0]=a3[0]=1;
	ct[0]=0;
	for(int i=1;i<=n;i++)
	{
		a1[i]=1ll*a1[i-1]*bs1%mod1;
		a2[i]=1ll*a2[i-1]*bs2%mod2;
		a3[i]=1ll*a3[i-1]*bs3%mod3;
		if(i>1&&s[i]=='1'&&s[i-1]=='1')
		{
			h1[i]=h1[i-2],h2[i]=h2[i-2],h3[i]=h3[i-2];
			//a1[i]=a1[i-2],a2[i]=a2[i-2],a3[i]=h3[i-2];
			vis[i]=1;
			ct[i]=ct[i-2];
			continue;
		}
		h1[i]=(1ll*h1[i-1]*bs1+s[i]-'0'+1)%mod1;
		h2[i]=(1ll*h2[i-1]*bs2+s[i]-'0'+1)%mod2;
		h3[i]=(1ll*h3[i-1]*bs3+s[i]-'0'+1)%mod3;
		ct[i]=ct[i-1]+1;
	}
	nxt[n+1]=n+1;
	for(int i=n;i>0;i--)
	{
		nxt[i]=i;
		if(i<n&&s[i]=='1'&&s[i+1]=='1') nxt[i]=nxt[i+2];
	}
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,ct=%d,h=%d,%d,%d\n",i,ct[i],h1[i],h2[i],h3[i]);
	for(int i=1;i<=m;i++)
	{
		int l1,l2,len,h1,h2,h3,h4,h5,h6;
		scanf("%d%d%d",&l1,&l2,&len);
		gethsh(l1,l1+len-1,h1,h2,h3);
		gethsh(l2,l2+len-1,h4,h5,h6);
		if(h1==h4&&h2==h5&&h3==h6) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
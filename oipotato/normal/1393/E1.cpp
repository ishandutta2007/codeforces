#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int ANSMOD=(int)1e9+7;
const int P=37,MOD=(int)1e9+7;
const int N=(int)1e6+10;
int f[N],save[N],h[N],g[N][2],ha[N],pw[N],n,len[N];
char s[N];
inline void add(int&x,int y){x+=y;if(x>=ANSMOD)x-=ANSMOD;}
int H(int l,int r){return (ha[r]-1ll*ha[l-1]*pw[r-l+1]%MOD+MOD)%MOD;}
int hsh(int l,int len,int x)
{
	if(l+len-1>=x)return (1ll*H(l,x-1)*pw[len-(x-l)]+H(x+1,l+len))%MOD;
	else return H(l,l+len-1);
}
bool cmp(int l1,int r1,int x,int l2,int r2,int y)
{
	int l=0,r=min(r1-l1+1,r2-l2+1);
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(hsh(l1,mid,x)!=hsh(l2,mid,y))r=mid;else l=mid;
	}
	return l1+l+1>r1||(l2+l+1<=r2&&s[l1+l>=x?l1+l+1:l1+l]<s[l2+l>=y?l2+l+1:l2+l]);
}
void work(int l1,int r1,int x,int F,int l2,int r2,int id)
{
	int len1=r1-l1+1,len2=r2-l2+1;
	if(cmp(l1,r1,x,l2,r2+1,r2+1))add(save[id],F);
	int l=0,r=min(len1-1,len2)+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(hsh(l1,mid,x)!=hsh(l2,mid,r2+1))r=mid;else l=mid;
	}
	if(l2+l+1<=r2&&(l1+l+1>r1||s[l1+l>=x?l1+l+1:l1+l]<s[l2+l]))add(h[l2+l+1],F);
	if(l2+l<=r2&&cmp(l1,r1,x,l2,r2,l2+l))add(f[l2+l],F);
	if(l)add(g[l2+l-1][cmp(l1,r1,x,l2,r2,l2+l-1)],F);
}
int main()
{
	scanf("%d",&n);
	pw[0]=1;
	rep(i,1000000)pw[i]=1ll*pw[i-1]*P%MOD;
	int now=1;
	rep(i,n)
	{
		scanf("%s",s+now);
		len[i]=strlen(s+now);
		for(int j=now;j<now+len[i];j++)ha[j]=(1ll*ha[j-1]*P+s[j]-'a'+1)%MOD;
		now+=len[i];
	}
	now=1;
	rep(i,n)
	{
		if(i==1){rep(j,len[i])f[j]=1;save[i]=1;}
		else
		{
			for(int j=now+1;j<now+len[i];j++)add(h[j],h[j-1]);
			for(int j=now;j<now+len[i];j++)add(f[j],h[j]);
			int sum=0,ok=0;
			for(int j=now+len[i]-1;j>=now;j--)
			{
				add(sum,g[j][0]);add(sum,g[j][1]);
				add(ok,g[j][1]);
				if(j+1<now+len[i])
				{
					if(s[j]>s[j+1])ok=0;
					else if(s[j]<s[j+1])ok=sum;
				}
				add(f[j],ok);
			}
		}
		if(i==n)
		{
			int ans=save[i];
			for(int j=now;j<now+len[i];j++)add(ans,f[j]);
			printf("%d\n",ans);
		}
		else
		{
			for(int j=now;j<now+len[i];j++)if(f[j])work(now,now+len[i]-1,j,f[j],now+len[i],now+len[i]+len[i+1]-1,i+1);
			if(save[i])work(now,now+len[i],now+len[i],save[i],now+len[i],now+len[i]+len[i+1]-1,i+1);
		}
		now+=len[i];
	}
	return 0;
}
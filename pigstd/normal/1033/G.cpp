#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=110;
int n,m,b[M],c1[M],c2[M],p[M],tot,la=-1;
long long a[M],ans[10];

//bool cmp(int a,int b){return c1[a]+c2[a]>c1[b]+c2[b];}
bool cmp(int a,int b){return a>b;}

int calc(int x,int y)
{
	if (x+y!=la)
	{
		la=x+y;
		for (int i=1;i<=n;i++)b[i]=a[i]%(x+y);
		sort(b+1,b+1+n,cmp);
	}
//	for (int i=1;i<=n;i++)assert(b[i-1]<=b[i]);
	for (int i=1;i<=n;i++)c1[i]=b[i]/x,c2[i]=b[i]/y;
	int f1=0,f2=0,r1=0,r2=0;tot=0;
	for (int i=1;i<=n;i++)
		if (c1[i]==0)f2+=c2[i];
		else if (c2[i]==0)f1+=c1[i];
		else p[++tot]=i;
	int cnt1=f1,cnt2=f2,cnt3=f1,cnt4=f2;
//	for (int i=2;i<=tot;i++)
//		assert(c1[p[i-1]]+c2[p[i-1]]<=c1[p[i]]+c2[p[i]]);
//	sort(p+1,p+1+tot,cmp);
	for (int i=1;i<=tot;i+=2)cnt1+=c1[p[i]],cnt4+=c2[p[i]];
	for (int i=2;i<=tot;i+=2)cnt2+=c2[p[i]],cnt3+=c1[p[i]];
	if (cnt1>cnt2)r1=1;
	if (cnt3>=cnt4)r2=1;
	if (r1&&r2)return 1;
	else if (!r1&&!r2)return 2;
	else if (r1&&!r2)return 3;
	else return 4;
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("2.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=2;i<=2*m;i++)
	{
		int tl=1,tr=i-1,now=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (calc(Mid,i-Mid)==1)now=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
//		while(now+1<i&&calc(now+1,i-now-1)==1)now++;
//		while(now>0&&calc(now,i-now)!=1)now--; 
		int tmp=max(now,i-m-1);
		ans[1]+=tmp-max(i-m-1,0),ans[2]+=tmp-max(i-m-1,0);
//		cout<<now<<' ';
		if (tmp*2!=i-1)ans[calc(tmp+1,i-(tmp+1))]+=i-1-2*tmp;
//		cout<<now<<' ';
	}
	for (int i=1;i<5;i++)cout<<ans[i]<<' ';
	return 0;
}
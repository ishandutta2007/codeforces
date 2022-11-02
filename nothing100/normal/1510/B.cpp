#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const int N=1050,INF=1e9+7,NPOS=-1;
struct Matrix
{
	int n;
	int a[N][N];
};
struct KuhnMunkres:Matrix
{
	int hl[N],hr[N],slk[N];
	int fl[N],fr[N],vl[N],vr[N],pre[N],q[N],ql,qr;
	int check(int i)
	{
		if(vl[i]=1,fl[i]!=NPOS)return vr[q[qr++]=fl[i]]=1;
		while(i!=NPOS)swap(i,fr[fl[i]=pre[i]]);
		return 0;
	}
	void bfs(int s)
	{
		fill(slk,slk+n,INF),fill(vl,vl+n,0),fill(vr,vr+n,0);
		for(vr[q[ql=0]=s]=qr=1;;)
		{
			for(ll d; ql<qr;)
				for(int i=0,j=q[ql++]; i<n; ++i)
					if(!vl[i]&&slk[i]>=(d=hl[i]+hr[j]-a[i][j]))
						if(pre[i]=j,d)slk[i]=d;
						else if(!check(i))return;
			ll d=INF;
			for(int i=0; i<n; ++i)
				if(!vl[i]&&d>slk[i])d=slk[i];
			for(int i=0; i<n; ++i)
			{
				if(vl[i])hl[i]+=d;
				else slk[i]-=d;
				if(vr[i])hr[i]-=d;
			}
			for(int i=0; i<n; ++i)
				if(!vl[i]&&!slk[i]&&!check(i))return;
		}
	}
	void ask()
	{
		fill(fl,fl+n,NPOS),fill(fr,fr+n,NPOS),fill(hr,hr+n,0);
		for(int i=0; i<n; ++i)hl[i]=*max_element(a[i],a[i]+n);
		for(int j=0; j<n; ++j)bfs(j);
	}
} km;
int f[1050],d,n,ans,fir;
char tmp[20]; 
void dfs(int x,int y){
	f[y]=0;
	for (int j=0;j<d;j++)
	if (((x^y)>>j)&1) printf("%d ",j);
	if (km.a[y][km.fl[y]]) dfs(y,km.fl[y]);
}
int main()
{
	scanf("%d%d",&d,&n);
	for (int i=0;i<n;i++){
		int now=0,fn=0;
		scanf("%s",tmp);
		for (int i=0;i<d;i++){
			fn=fn+tmp[i]-'0';
			now=now+(tmp[i]-'0')*(1<<i);
		}
		f[now]=fn;
		ans=ans+fn+1;
	}
	for (int i=1;i<(1<<d);i++)
	if (f[i]){
		for (int j=i+1;j<(1<<d);j++)
		if (f[j]&&((i&j)==i)) km.a[i][j]=f[i]+1;
	}
	km.n=(1<<d),km.ask();
	for(int i=1; i<(1<<d); i++){
		ans-=km.a[i][km.fl[i]];
	}
	ans--;
	printf("%d\n",ans);
	fir=1;
	for (int i=0;i<(1<<d);i++)
	if (f[i]){
		if (!fir) printf("R ");
		dfs(0,i);
		fir=0;
	}
}
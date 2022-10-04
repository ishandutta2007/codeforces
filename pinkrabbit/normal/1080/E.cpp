#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
const int INF=0x3f3f3f3f;

int n,m;
int ha[3][30];
char mp[305][305];
int st[305][305];
int hv[3][305][305];
int t[3][305];
LL v[605]; int o[605];
int p[605];
LL Ans;

#define isp(x) (((x)&((x)-1))==0)

void manacher(){
	int N=n*2+1;
	memset(p,0,sizeof p);
	int id=0;
	F(i,1,N) if(o[i]){
		if(!o[i-1]){
			p[i]=1;
			id=i;
			continue;
		}
		if(i<id+p[id]) p[i]=min(p[2*id-i],id+p[id]-i);
		else p[i]=1;
		while(i-p[i]>=1&&i+p[i]<=N&&o[i-p[i]]&&o[i+p[i]]&&v[i-p[i]]==v[i+p[i]]) ++p[i];
		if(i+p[i]>=id+p[id]) id=i;
	}
	F(i,1,N) if(o[i]) Ans+=p[i]/2;
}

int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%s",mp[i]+1);
	F(j,0,2){
		F(i,0,25) ha[j][i]=i+1;
		random_shuffle(ha[j],ha[j]+26);
	}
	F(i,1,n) F(j,1,m){
		F(k,0,2) hv[k][i][j]=hv[k][i][j-1]+ha[k][mp[i][j]-'a'];
		st[i][j]=st[i][j-1]^(1<<(mp[i][j]-'a'));
	}
	F(c1,1,m) F(c2,c1,m){
		F(k,0,2) F(i,1,n) t[k][i]=hv[k][i][c2]-hv[k][i][c1-1];
		F(i,1,n) v[i]=100000000ll*t[0][i]+10000ll*t[1][i]+t[2][i];
		F(i,1,n)
			if(isp(st[i][c2]^st[i][c1-1])) o[i]=1;
			else o[i]=0;
		dF(i,n,1) v[i*2]=v[i], o[i*2]=o[i];
		F(i,1,n+1) v[i*2-1]=0, o[i*2-1]=1;
		manacher();
	}
	printf("%lld\n",Ans);
	return 0;
}
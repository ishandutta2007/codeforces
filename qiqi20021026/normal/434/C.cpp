#include<bits/stdc++.h>

using namespace std;

#define N 205

const int mod=1000000007;
int n,m,p,ll,rr,cnt,x;
int q[N],l[N],r[N],len,c[N][20],fa[N],tr[N][20],f[N][N][505][2],val[N],val2[N];

inline void upd(int &x,int y){x=(x+y)%mod;}

int trans(int x,int y){
	if (tr[x][y]!=-1) return tr[x][y];
	for (;x&&!c[x][y];x=fa[x]);
	return tr[x][y]=c[x][y];
}

int calc(int x,int d[]){
	if (x==0) return 0;
	memset(f,0,sizeof f);
	int t=trans(0,d[x]); f[x][t][val[t]][1]=1;
	for (int i=1;i<d[x];++i){
		int t=trans(0,i);
		upd(f[x][t][val[t]][0],1);
	}
	for (int i=x;i>1;--i){
		for (int j=1;j<m;++j){
			int t=trans(0,j);
			upd(f[i-1][t][val[t]][0],1);
		}
		for (int j=0;j<=cnt;++j)
			for (int k=0;k<=p;++k){
				if (!f[i][j][k][0]&&!f[i][j][k][1]) continue;
				for (int l=0;l<m;++l){
					int t=trans(j,l);
					if (k+val[t]<=p){
						upd(f[i-1][t][k+val[t]][0],f[i][j][k][0]);
						if (l<d[i-1]) upd(f[i-1][t][k+val[t]][0],f[i][j][k][1]);
						if (l==d[i-1]) upd(f[i-1][t][k+val[t]][1],f[i][j][k][1]);
					}
				}
			}
	}
	int ret=0;
	for (int j=0;j<=cnt;++j)
		for (int k=0;k<=p;++k) upd(ret,f[1][j][k][0]+f[1][j][k][1]%mod);
	return ret;
}

int main(){
	scanf("%d%d%d",&n,&m,&p);
	scanf("%d",&ll); for (int i=ll;i;--i) scanf("%d",&l[i]);
	for (int i=1;i<=ll;++i) if (!l[i]) l[i]=m-1; else{--l[i]; break;}
	for (;ll&&!l[ll];--ll);
	scanf("%d",&rr); for (int i=rr;i;--i) scanf("%d",&r[i]);
	for (int i=1;i<=n;++i){
		scanf("%d",&len);
		int xb=0;
		for (int j=1;j<=len;++j){
			scanf("%d",&x);
			if (!c[xb][x]) c[xb][x]=++cnt;
			xb=c[xb][x];
		}
		scanf("%d",&x);  val2[xb]+=x;
	}
	int tt=0,ww=1; q[ww]=0;
	while (tt<ww){
		int u=q[++tt];
		for (int i=0,v;i<m;++i) if (v=c[u][i]){
			if (u==0) fa[v]=0;
			else{
				int o;
				for (o=fa[u];o&&!c[o][i];o=fa[o]);
				fa[v]=c[o][i];
			}
			q[++ww]=v;
		}
	}
	memset(tr,-1,sizeof tr);
	for (int i=1;i<=cnt;++i)
		for (int j=i;j;j=fa[j]) val[i]+=val2[j];
	printf("%d\n",(calc(rr,r)-calc(ll,l)+mod)%mod);
	
	return 0;
}
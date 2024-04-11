// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,ncnt,rcnt;
int a[805][260],piv[260],f[260],c[70][70],vis[260][260][260],res[260],to[260],lab[260],val[260];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx!=fy) f[fx]=fy;
}

bool gauss(){
//	cout<<"gauss "<<endl;
//	for(int i=1;i<=rcnt;i++){
//		for(int j=1;j<=ncnt+1;j++) cout<<a[i][j]<<' ';
//		cout<<endl;
//	}
	int now=1;
	for(int i=1;i<=ncnt;i++) piv[i]=0;
	for(int i=1;i<=ncnt;i++){
		int pl=-1;
		for(int j=now;j<=rcnt;j++){
			if(a[j][i]){
				pl=j;
				break;
			}
		}
		if(pl<0) continue;
		piv[i]=now;
		for(int j=i;j<=ncnt+1;j++) swap(a[now][j],a[pl][j]);
		if(a[now][i]==2){
			for(int j=i;j<=ncnt+1;j++) a[now][j]=a[now][j]*2%3;
		}
		for(int j=1;j<=rcnt;j++){
			if(!a[j][i]) continue;
			if(j==now) continue;
			int tmp=a[j][i];
			for(int k=i;k<=ncnt+1;k++) a[j][k]=(a[j][k]+9-a[now][k]*tmp)%3;
		}
		now++;
	}
	for(int i=now;i<=rcnt;i++) if(a[i][ncnt+1]) return false;
	for(int i=ncnt;i>=1;i--){
		if(piv[i]) continue;
		if(res[to[i]]){
			for(int j=1;j<=rcnt;j++) a[j][ncnt+1]=(a[j][ncnt+1]+9-a[j][i]*res[to[i]])%3,a[j][i]=0;
		}
		else{
			res[to[i]]=3;
			for(int j=1;j<=rcnt;j++) a[j][i]=0;
		}
	}
	for(int i=1;i<=ncnt;i++){
		if(piv[i]){
			if(res[to[i]]&&res[to[i]]!=a[piv[i]][ncnt+1]) return false;
			res[to[i]]=a[piv[i]][ncnt+1]+(a[piv[i]][ncnt+1]==0)*3;
		}
	}
	return true;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=0;
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint(); val[i]=readint();
			c[x][y]=c[y][x]=i;
		}
		for(int i=1;i<=m;i++) f[i]=i;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!c[i][j]) continue;
				for(int k=j+1;k<=n;k++){
					if(!c[i][k]||!c[j][k]) continue;
					for(int l=k+1;l<=n;l++){
						if(!c[i][l]||!c[j][l]||!c[k][l]) continue;
						merge(c[i][j],c[k][l]);
						merge(c[i][k],c[j][l]);
						merge(c[i][l],c[j][k]);
					}
				}
			}
		}
		for(int i=1;i<=m;i++) res[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(c[i][j]&&val[c[i][j]]>0)
					res[getf(c[i][j])]=val[c[i][j]];
		ncnt=rcnt=0;
		for(int i=1;i<=m;i++) if(getf(i)==i&&!res[i]) lab[i]=++ncnt,to[ncnt]=i;
		bool fl=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(c[i][j]&&val[c[i][j]]>0&&res[getf(c[i][j])]!=val[c[i][j]]) fl=1;
		if(fl){
			printf("-1\n");
			continue;
		}
		vector<pair<pii,int> > gar(0);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!c[i][j]) continue;
				for(int k=j+1;k<=n;k++){
					if(!c[i][k]||!c[j][k]) continue;
					int fi=getf(c[i][j]),fj=getf(c[i][k]),fk=getf(c[j][k]);
					if(fi>fj) swap(fi,fj);
					if(fi>fk) swap(fi,fk);
					if(fj>fk) swap(fj,fk);
					if(vis[fi][fj][fk]) continue;
					vis[fi][fj][fk]=1;
					gar.pb(mp(mp(fi,fj),fk));
//					cout<<"??? "<<fi<<' '<<fj<<' '<<fk<<endl;
					rcnt++;
					if(res[fi]) a[rcnt][ncnt+1]+=res[fi];
					else a[rcnt][lab[fi]]++;
					if(res[fj]) a[rcnt][ncnt+1]+=res[fj];
					else a[rcnt][lab[fj]]++;
					if(res[fk]) a[rcnt][ncnt+1]+=res[fk];
					else a[rcnt][lab[fk]]++;
					a[rcnt][lab[fi]]%=3;
					a[rcnt][ncnt+1]=(3-a[rcnt][ncnt+1]%3)%3;
				}
			}
		}
		for(auto r:gar) vis[r.fi.fi][r.fi.se][r.se]=0;
		if(!gauss()){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=m;i++) printf("%d ",res[getf(i)]);
		printf("\n");
	}
	return 0;
}
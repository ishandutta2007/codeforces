#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,cnt,tot;
int rk[15],now[15],v[1005],nxt[1005],h[15],d[2005];
ld c[15][15];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

ld gauss(int l){
	ld ans=1;
	for(int i=1;i<=l;i++){
		int pl=i;
		for(int j=i+1;j<=l;j++) if(c[j][i]!=0) pl=j;
		if(pl!=i) ans*=-1;
		for(int j=i;j<=l;j++) swap(c[i][j],c[pl][j]);
		ans*=c[i][i];
		if(!c[i][i]) return -100;
		for(int j=i+1;j<=l;j++){
			ld tmp=c[j][i]/c[i][i];
			for(int k=l;k>=i;k--) c[j][k]-=c[i][k]*tmp;
		}
	}
	return ans;
}

int main(){
	n=readint(); m=readint(); k=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	for(int i=0;i<(1<<n)-1;i++){
		for(int j=1;j<=n;j++) now[j]=(i>>(j-1))&1;
		cnt=0;
		for(int j=1;j<=n;j++) if(!now[j]) rk[j]=++cnt;
		memset(c,0,sizeof(c));
		for(int j=1;j<=n;j++){
			if(now[j]) continue;
			for(int p=h[j];p;p=nxt[p]) if(!now[v[p]]) c[rk[j]][rk[j]]++,c[rk[j]][rk[v[p]]]--;
		}
		int ret=(int)(gauss(cnt-1)+0.5);
		if(ret<0) continue;
		for(int j=1;j<=n;j++){
			if(!now[j]) continue;
			int num=0;
			for(int p=h[j];p;p=nxt[p]) if(!now[v[p]]) num++;
			ret*=num;
		}
		d[i]=cnt&1?-ret:ret;
	}
	for(int i=1;i<=n;i++) for(int j=0;j<(1<<n);j++) if(!((j>>(i-1))&1)) d[j]+=d[j+(1<<(i-1))];
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		int num=0;
		for(int j=1;j<=n;j++) num+=(i>>(j-1))&1;
		if(num==k) ans+=d[i];
	}
	printf("%d\n",(int)fabs(ans));
	return 0;
}
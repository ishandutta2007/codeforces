#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,acnt,gcc,tot,rt;
pair<pair<int,int>,int> ans[100005];
int du[1005],v[2005],nxt[2005],c[2005],h[1005],gc[5];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void fuck(int x,int t1,int t2,int gg){
	ans[++acnt]=mp(mp(x,t1),gg/2);
	ans[++acnt]=mp(mp(x,t2),gg/2);
	ans[++acnt]=mp(mp(t1,t2),-gg/2);
}

pii dfs2(int u,int fa){
	pii now=mp(0,0),tmp;
	if(du[u]==1) now.fi=u;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		tmp=dfs2(v[p],u);
		if(!now.fi) now.fi=tmp.fi;
		else if(!now.se) now.se=tmp.fi;
	}
	return now;
}

pii dfs(int u,int fa){
	int kk[5],sht=0;
	pii now=mp(0,0),tmp,ttmp;
	if(du[u]==1) now.fi=u;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		tmp=dfs(v[p],u);
		if(!now.fi) now.fi=tmp.fi;
		else if(!now.se) now.se=tmp.fi;
		if(du[v[p]]==1){
			ttmp=dfs2(u,v[p]);
			fuck(v[p],ttmp.fi,ttmp.se,c[p]);
		}
		else{
			ttmp=dfs2(u,v[p]);
			ans[++acnt]=mp(mp(ttmp.fi,tmp.fi),c[p]/2);
			ans[++acnt]=mp(mp(ttmp.se,tmp.se),c[p]/2);
			ans[++acnt]=mp(mp(ttmp.fi,ttmp.se),-c[p]/2);
			ans[++acnt]=mp(mp(tmp.fi,tmp.se),-c[p]/2);
		}
	}
	return now;
}

int main(){
	n=readint();
	int x,y,z;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint(); z=readint();
		du[x]++,du[y]++;
		addedge(x,y,z);
	}
	for(int i=1;i<=n;i++) if(du[i]==2) return printf("NO\n"),0;
	for(int i=1;i<=n;i++) if(du[i]>1) rt=i;
	printf("YES\n");
	if(!rt){
		printf("1\n1 2 %d\n",c[1]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(du[i]==1){
			gc[++gcc]=i;
			if(gcc==3) break;
		}
	}
	dfs(rt,-1);
	cout<<acnt<<endl;
	for(int i=1;i<=acnt;i++) printf("%d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se);
	return 0;
}
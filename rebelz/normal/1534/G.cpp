#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,rt,cnt; ll ans;
int siz[1600005],sum[1600005],len[1600005],k[1600005],tag[1600005],ch[1600005][2];
pii A[800005];
mt19937 mrand(23498);

void update(int u){
	siz[u]=1+siz[ch[u][0]]+siz[ch[u][1]];
	sum[u]=len[u]+sum[ch[u][0]]+sum[ch[u][1]];
}

void pushdown(int u){
	if(tag[u]){
		if(ch[u][0]) tag[ch[u][0]]+=tag[u],k[ch[u][0]]+=tag[u];
		if(ch[u][1]) tag[ch[u][1]]+=tag[u],k[ch[u][1]]+=tag[u];
		tag[u]=0;
	}
}

void split1(int u,int t,int &x,int &y){
	if(!u) return (void)(x=y=0);
	pushdown(u);
	if(sum[ch[u][0]]+len[u]<=t) x=u,split1(ch[u][1],t-sum[ch[u][0]]-len[u],ch[x][1],y);
	else y=u,split1(ch[u][0],t,x,ch[y][0]);
	update(u);
}

void split2(int u,int t,int &x,int &y){
	if(!u) return (void)(x=y=0);
	pushdown(u);
	if(k[u]<=t) x=u,split2(ch[u][1],t,ch[x][1],y);
	else y=u,split2(ch[u][0],t,x,ch[y][0]);
	update(u);
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	pushdown(x); pushdown(y);
	if(mrand()%(siz[x]+siz[y])<siz[x]){
		ch[x][1]=merge(ch[x][1],y); update(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]); update(y);
		return y;
	}
}

void print(int u){
	pushdown(u);;
	if(ch[u][0]) print(ch[u][0]);
	cout<<"dfs "<<k[u]<<' '<<len[u]<<endl;
	if(ch[u][1]) print(ch[u][1]);
}

void add(int x){
	int a,b,c;
	split2(rt,-1,a,b);
	split2(b,0,b,c);
	if(!b){
		b=++cnt;
		k[b]=0,len[b]=x;
		update(b);
	}
	else{
		len[b]+=x;
		update(b);
	}
	rt=merge(merge(a,b),c);
//	print(rt);
}

void dfs(int u){
	pushdown(u);
	if(ch[u][0]) dfs(ch[u][0]);
	if(k[u]<0) ans+=1ll*len[u]*k[u];
	if(ch[u][1]) dfs(ch[u][1]);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) A[i].fi=readint(),A[i].se=readint();
	sort(A+1,A+n+1,[&](pii x,pii y){return x.fi+x.se<y.fi+y.se;});
	int now=0;
	rt=++cnt;
	k[cnt]=0,len[cnt]=sum[cnt]=1,siz[cnt]=1;
	ll st=0;
	for(int i=1;i<=n;i++){
		if(now<A[i].fi+A[i].se) add(A[i].fi+A[i].se-now),now=A[i].fi+A[i].se;
		A[i].fi++,A[i].se++;
		int a,b,c;
		split1(rt,A[i].fi-1,a,b);
		int x=b;
		while(ch[x][0]) x=ch[x][0];
		split1(b,len[x],b,c);
		st+=A[i].fi;
		if(sum[a]+len[b]==A[i].fi) a=merge(a,b);
		else{
			cnt++;
			k[cnt]=k[b],len[cnt]=sum[a]+len[b]-A[i].fi;
			len[b]=A[i].fi-sum[a];
			update(cnt),update(b);
			a=merge(a,b),c=merge(cnt,c);
		}
		if(a) tag[a]--,k[a]--;
		if(c) tag[c]++,k[c]++;
		rt=merge(a,c);
//		print(rt);
	}
	dfs(rt);
	printf("%lld\n",ans+st);
	return 0;
}
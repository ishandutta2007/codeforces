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

int n,rt;
int siz[500005],lmn[500005],lmx[500005],rmn[500005],rmx[500005],val[500005],sum[500005],ch[500005][2];
bool tag[500005];
char s[500005];
mt19937 mrand(1);

void update(int u){
	siz[u]=1+siz[ch[u][0]]+siz[ch[u][1]];
	sum[u]=val[u]+sum[ch[u][0]]+sum[ch[u][1]];
	lmn[u]=min(lmn[ch[u][0]],min(sum[ch[u][0]]+val[u],sum[ch[u][0]]+val[u]+lmn[ch[u][1]]));
	lmx[u]=max(lmx[ch[u][0]],max(sum[ch[u][0]]+val[u],sum[ch[u][0]]+val[u]+lmx[ch[u][1]]));
	rmn[u]=min(rmn[ch[u][1]],min(sum[ch[u][1]]+val[u],sum[ch[u][1]]+val[u]+rmn[ch[u][0]]));
	rmx[u]=max(rmx[ch[u][1]],max(sum[ch[u][1]]+val[u],sum[ch[u][1]]+val[u]+rmx[ch[u][0]]));
}

void addtag(int u){
	tag[u]^=1,val[u]*=-1,sum[u]*=-1,swap(ch[u][0],ch[u][1]);
	int tlmn=lmn[u],tlmx=lmx[u],trmn=rmn[u],trmx=rmx[u];
	lmn[u]=-trmx,lmx[u]=-trmn,rmn[u]=-tlmx,rmx[u]=-tlmn;
}

void pushdown(int u){
	if(tag[u]){
		if(ch[u][0]) addtag(ch[u][0]);
		if(ch[u][1]) addtag(ch[u][1]);
		tag[u]=0;
	}
}

void split(int u,int k,int &x,int &y){
	if(!u) return (void)(x=y=0);
	pushdown(u);
	if(k<=siz[ch[u][0]]) y=u,split(ch[u][0],k,x,ch[y][0]);
	else x=u,split(ch[u][1],k-siz[ch[u][0]]-1,ch[x][1],y);
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

int ask1(int u,int x,int s){
//	cout<<"ask1 "<<u<<' '<<siz[u]<<' '<<lmn[u]<<endl;
	pushdown(u);
	if(x+lmn[u]>=0) return n+1;
	if(x+lmn[ch[u][0]]<=-1) return ask1(ch[u][0],x,s);
	if(x+sum[ch[u][0]]+val[u]<=-1) return s+siz[ch[u][0]]+1;
	return ask1(ch[u][1],x+sum[ch[u][0]]+val[u],s+siz[ch[u][0]]+1);
}

int ask2(int u,int x,int s){
	pushdown(u);
	if(x+lmx[u]<=0) return n+1;
	if(x+lmx[ch[u][0]]>=1) return ask2(ch[u][0],x,s);
	if(x+sum[ch[u][0]]+val[u]>=1) return s+siz[ch[u][0]]+1;
	return ask2(ch[u][1],x+sum[ch[u][0]]+val[u],s+siz[ch[u][0]]+1);
}

int find(int u,int x){
	pushdown(u);
	if(x==siz[ch[u][0]]+1) return val[u];
	if(x<=siz[ch[u][0]]) return find(ch[u][0],x);
	return find(ch[u][1],x-siz[ch[u][0]]-1);
}

void work(){
	scanf("%s",s+1); n=strlen(s+1);
	rt=0;
	for(int i=1;i<=n;i++) siz[i]=1,val[i]=sum[i]=lmn[i]=lmx[i]=rmn[i]=rmx[i]=(s[i]=='1'?1:-1),ch[i][0]=ch[i][1]=tag[i]=0;
	for(int i=1;i<=n;i++) rt=merge(rt,i);
	int a,b,c,d;
	for(int i=1;i<=n;i++){
		if(find(rt,i)<0) continue;
		split(rt,i-1,a,b);
		int pl1=i-1+ask1(b,0,0);
		if(pl1>n){
			rt=merge(a,b);
			continue;
		}
		split(b,pl1-i+1,b,c);
		int pl2=pl1+ask2(c,0,0);
		if(pl2>n){
			rt=merge(merge(a,b),c);
			continue;
		}
//		cout<<"test "<<i<<' '<<pl1<<' '<<pl2<<endl;
		split(c,pl2-pl1,c,d);
		b=merge(b,c);
		addtag(b);
		rt=merge(merge(a,b),d);
//		for(int j=1;j<=n;j++) cout<<find(rt,j)<<' ';
//		cout<<endl;
	}
	for(int i=1;i<=n;i++) printf("%d",find(rt,i)>0?1:0);
	printf("\n");
}

int main(){
	int T=readint();
	lmn[0]=rmn[0]=1<<30,lmx[0]=rmx[0]=-(1<<30);
	while(T--) work();
	return 0;
}
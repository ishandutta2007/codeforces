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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,blo,cnt;
int st[405],en[405],pos[405][100005],mx[405],bl[100005],fa[100005],tag[405],siz[100005],a[100005],val[100005];

void init(){
	blo=sqrt(n);
	for(int i=1;i<=n;i+=blo) st[++cnt]=i,en[cnt]=i+blo-1;
	en[cnt]=n;
	for(int i=1;i<=cnt;i++) for(int j=st[i];j<=en[i];j++) bl[j]=i,mx[i]=max(mx[i],a[j]);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1,val[i]=a[i];
	for(int i=1;i<=cnt;i++) for(int j=st[i];j<=en[i];j++)
		if(!pos[i][a[j]]) pos[i][a[j]]=j;
		else fa[j]=pos[i][a[j]],siz[pos[i][a[j]]]+=siz[j];
}

void update(int x){while(!pos[x][mx[x]])mx[x]--;}
int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}

void brc(int l,int r,int x){
	int k=bl[l];
	mx[k]=0;
	for(int i=st[k];i<=en[k];i++) a[i]=val[getf(i)]-tag[k];
	for(int i=st[k];i<=en[k];i++) pos[k][a[i]+tag[k]]=0,fa[i]=i,siz[i]=1,mx[k]=max(mx[k],a[i]);
	tag[k]=0;
	for(int i=l;i<=r;i++) if(a[i]>x) a[i]-=x;
	for(int i=st[k];i<=en[k];i++)
		if(!pos[k][a[i]]) pos[k][a[i]]=i,val[i]=a[i];
		else fa[i]=pos[k][a[i]],siz[pos[k][a[i]]]+=siz[i];
	update(k);
}

void modify(int k,int x){
	if(mx[k]-tag[k]<2*x){
		for(int i=tag[k]+x+1;i<=mx[k];i++){
			if(!pos[k][i-x]) pos[k][i-x]=pos[k][i],val[pos[k][i-x]]=i-x,pos[k][i]=0;
			else fa[pos[k][i]]=pos[k][i-x],siz[pos[k][i-x]]+=siz[pos[k][i]],pos[k][i]=0;
		}
		update(k);
	}
	else{
		for(int i=tag[k]+1;i<=tag[k]+x;i++){
			if(!pos[k][i+x]) pos[k][i+x]=pos[k][i],val[pos[k][i+x]]=i+x,pos[k][i]=0;
			else fa[pos[k][i]]=pos[k][i+x],siz[pos[k][i+x]]+=siz[pos[k][i]],pos[k][i]=0;
		}
		tag[k]+=x;
	}
}

void change(int l,int r,int x){
	if(bl[l]==bl[r]) return brc(l,r,x);
	brc(l,en[bl[l]],x); brc(st[bl[r]],r,x);
	for(int i=bl[l]+1;i<=bl[r]-1;i++) modify(i,x);
}

int brq(int l,int r,int x){
	int ret=0;
	for(int i=l;i<=r;i++) ret+=val[getf(i)]-tag[bl[i]]==x;
	return ret;
}

int getans(int k,int x){return tag[k]+x<=100000?siz[pos[k][tag[k]+x]]:0;}

int query(int l,int r,int x){
	if(bl[l]==bl[r]) return brq(l,r,x);
	int ret=brq(l,en[bl[l]],x)+brq(st[bl[r]],r,x);
	for(int i=bl[l]+1;i<=bl[r]-1;i++) ret+=getans(i,x);
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	init();
	int opt,x,y,z;
	for(int i=1;i<=m;i++){
		opt=readint(); x=readint(); y=readint(); z=readint();
		if(opt==1) change(x,y,z);
		else printf("%d\n",query(x,y,z));
	}
	return 0;
}
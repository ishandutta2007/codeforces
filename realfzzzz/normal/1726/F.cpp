#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5,maxs=13e6;
int n,t,g[maxn],c[maxn];
ll s[maxn];
int m,ord[maxn*2];
int sz=0,ch[maxs][2];
pair<int,int> mx[maxs];
int add[maxs];
int newnode(int l,int r){
	int o=++sz;
	mx[o]={0,-l};
	if(l==r) return o;
	int mid=l+(r-l)/2;
	ch[o][0]=newnode(l,mid);
	ch[o][1]=newnode(mid+1,r);
	return o;
}
int newnode(int x){
	int o=++sz;
	ch[o][0]=ch[x][0];
	ch[o][1]=ch[x][1];
	mx[o]=mx[x];
	add[o]=add[x];
	return o;
}
void modify(int o,int l,int r,int ql,int qr,int k){
	if(ql<=l&&qr>=r){
		mx[o].first+=k;
		add[o]+=k;
		return;
	}
	int mid=l+(r-l)/2;
	if(ql<=mid){
		ch[o][0]=newnode(ch[o][0]);
		modify(ch[o][0],l,mid,ql,qr,k);
	}
	if(qr>mid){
		ch[o][1]=newnode(ch[o][1]);
		modify(ch[o][1],mid+1,r,ql,qr,k);
	}
	mx[o]=max(mx[ch[o][0]],mx[ch[o][1]]);
	mx[o].first+=add[o];
}
pair<int,int> query(int o,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return {-1,0};
	if(ql<=l&&qr>=r) return mx[o];
	int mid=l+(r-l)/2;
	auto s=max(query(ch[o][0],l,mid,ql,qr),query(ch[o][1],mid+1,r,ql,qr));
	s.first+=add[o];
	return s;
}
int rt[maxn];
ll f[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	t=read();
	for(int i=1;i<=n;i++){
		g[i]=read();
		c[i]=(read()-c[1]+t)%t;
	}
	c[1]=0;
	for(int i=1;i<n;i++) s[i+1]=s[i]+read();
	for(int i=1;i<=n;i++){
		ord[i*2-1]=(s[i]+c[i]-g[i]+1+t)%t;
		ord[i*2]=(s[i]+c[i]+1)%t;
	}
	ord[n*2+1]=0;
	sort(ord+1,ord+n*2+2);
	m=unique(ord+1,ord+n*2+2)-ord-1;
	rt[0]=newnode(1,m);
	for(int i=1;i<=n;i++){
		int l,r;
		l=lower_bound(ord+1,ord+m+1,(s[i]+c[i]-g[i]+1+t)%t)-ord;
		r=lower_bound(ord+1,ord+m+1,(s[i]+c[i]+1)%t)-ord;
		rt[i]=newnode(rt[i-1]);
		if(l<r) modify(rt[i],1,m,l,r-1,1);
		else{
			modify(rt[i],1,m,l,m,1);
			if(r>1) modify(rt[i],1,m,1,r-1,1);
		}
	}
	for(int i=n;i>0;i--){
		int l=i,r=n;
		while(l<r){
			int mid=l+(r-l+1)/2,x=lower_bound(ord+1,ord+m+1,(s[i]+c[i])%t)-ord;
			if(query(rt[mid],1,m,x,x).first-query(rt[i],1,m,x,x).first==mid-i) l=mid;
			else r=mid-1;
		}
		if(r==n) f[i]=s[n]-s[i];
		else f[i]=f[r+1]+(s[i]+c[i]-s[r+1]%t-c[r+1]+t*2)%t+s[r+1]-s[i];
	}
	ll ans=9e18;
	for(int i=1;i<=n&&mx[rt[i]].first==i;i++)
		if(i==n) ans=s[n];
		else{
			int x=lower_bound(ord+1,ord+m+1,(s[i+1]+c[i+1]+1)%t)-ord,y;
			auto res=query(rt[i],1,m,x,m);
			if(res.first==i) y=ord[-res.second];
			else{
				res=query(rt[i],1,m,1,x-1);
				if(res.first==i) y=ord[-res.second];
				else continue;
			}
			ans=min(ans,f[i+1]+(y-s[i+1]%t-c[i+1]+t*2)%t+s[i+1]);
		}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
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

int n,x,ans;
int a[200005],cnt[200005],lst[200005],pre[200005],nxt[200005],mina[400005],sum[200005];
bool vis[200005],inc[200005];
vector<int> b[200005],c[200005],v[200005];

void calc(int p){
	mina[n]=1;
	for(int i=0;i<c[p].size();i++){
		int t=c[p][i];
		sum[i+1]=sum[i]+(a[t]==x?-1:1);
		if(mina[sum[i+1]+n]){
			int l,r,s=c[p][mina[sum[i+1]+n]-1];
			if(a[t]==x) r=nxt[t]-1;
			else r=nxt[lst[t]]-1;
			if(a[s]==x) l=pre[s]+1;
			else l=lst[s]+1;
			chkmax(ans,r-l+1);
		}
		else mina[sum[i+1]+n]=i+2;
	}
	for(int i=0;i<=c[p].size();i++) mina[sum[i]+n]=0;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int maxa=0,num=0;
	for(int i=1;i<=n;i++) cnt[a[i]]++,chkmax(maxa,cnt[a[i]]);
	for(int i=1;i<=n;i++) if(maxa==cnt[i]) num++;
	if(num>1) return printf("%d\n",n),0;
	for(int i=1;i<=n;i++) if(maxa==cnt[i]) x=i;
	for(int i=1;i<=n+1;i++){
		lst[i]=lst[i-1];
		if(a[i-1]==x) lst[i]=i-1;
	}
	a[n+1]=x;
	for(int i=1;i<=n+1;i++) if(a[i]==x) pre[i]=lst[i],nxt[lst[i]]=i;
	for(int i=1;i<=n;i++) v[a[i]].pb(i);
	for(int i=1;i<=n;i++){
		if(!v[i].size()||i==x) continue;
		int l=0,r=0;
		vector<int> gar(0);
		for(auto p:v[i]){
			if(p>r) l=lst[p],r=nxt[l];
			if(l){
				b[l].pb(i),gar.pb(l);
				nxt[pre[l]]=nxt[l];
				pre[nxt[l]]=pre[l];
				l=pre[l];
			}
			if(r<=n){
				b[r].pb(i),gar.pb(r);
				nxt[pre[r]]=nxt[r];
				pre[nxt[r]]=pre[r];
				r=nxt[r];
			}
		}
		reverse(gar.begin(),gar.end());
		for(auto p:gar) nxt[pre[p]]=pre[nxt[p]]=p;
	}
	vector<int> cur(0);
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			for(auto r:b[i]) c[r].pb(i),vis[r]=1;
			vector<int> tmp(0);
			for(auto r:cur){
				if(!vis[r]){
					calc(r);
					c[r].clear(),inc[r]=0;
				}
				else tmp.pb(r);
			}
			swap(cur,tmp);
			for(auto r:b[i]) vis[r]=0;
		}
		else{
			c[a[i]].pb(i);
			if(!inc[a[i]]) cur.pb(a[i]),inc[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++) if(c[i].size()) calc(i);
	printf("%d\n",ans);
	return 0;
}
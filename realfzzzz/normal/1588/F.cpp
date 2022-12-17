#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5,maxb=500;
int n,q,p[maxn];
ll a[maxn];
int S,B,L[maxb],R[maxb],pos[maxn];
ll s[maxb];
int pos2[maxn];
vector<int> vec[maxb];
int nxt[maxb],sz[maxb],s2[maxb][maxb];
ll tag[maxb];
vector<int> pl;
void merge(int x){
	for(int i:vec[x]){
		a[i]+=tag[x];
		s[pos[i]]+=tag[x];
	}
	tag[x]=0;
	for(int i:vec[nxt[x]]){
		a[i]+=tag[nxt[x]];
		s[pos[i]]+=tag[nxt[x]];
		vec[x].push_back(i);
		pos2[i]=x;
	}
	sz[x]+=sz[nxt[x]];
	for(int i=1;i<=B;i++) s2[x][i]+=s2[nxt[x]][i];
	sz[nxt[x]]=0;
	vec[nxt[x]]={};
	tag[nxt[x]]=0;
	memset(s2[nxt[x]],0,sizeof(s2[0]));
	pl.push_back(nxt[x]);
	nxt[x]=nxt[nxt[x]];
}
void split(int x,int k){
	int y=pl.back();
	pl.pop_back();
	tag[y]=tag[x];
	for(int i=k;i<sz[x];i++) vec[y].push_back(vec[x][i]);
	sz[y]=sz[x]-k;
	vec[x].resize(sz[x]=k);
	for(int i:vec[y]){
		pos2[i]=y;
		s2[y][pos[i]]++;
	}
	for(int i=1;i<=B;i++){
		s2[y][i]+=s2[y][i-1];
		s2[x][i]-=s2[y][i];
	}
	nxt[y]=nxt[x];
	nxt[x]=y;
}
void rebuild(int x){
	while(nxt[x]!=x&&sz[x]<S){
		merge(x);
		if(sz[x]>=S*2) split(x,sz[x]/2);
	}
}
void build(vector<int> vec2){
	int x=pl.back();
	pl.pop_back();
	sz[x]=vec2.size();
	vec[x]=vec2;
	for(int i:vec2){
		pos2[i]=x;
		s2[x][pos[i]]++;
	}
	for(int i=1;i<=B;i++) s2[x][i]+=s2[x][i-1];
}
void build(int x){
	vector<int> vec;
	int u=x;
	do{
		vec.push_back(u);
		u=p[u];
	}while(u!=x);
	build(vec);
}
void ruin(int x){
	for(int i:vec[x]){
		a[i]+=tag[x];
		s[pos[i]]+=tag[x];
		pos2[i]=0;
	}
	sz[x]=0;
	vec[x]={};
	tag[x]=0;
	memset(s2[x],0,sizeof(s2[x]));
	pl.push_back(x);
}
bool vis[maxn];
ll query(int l,int r){
	ll s=0;
	for(int i=l;i<=r;i++) s+=a[i]+(pos2[i]?tag[pos2[i]]:0);
	return s;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	S=sqrt(n);
	B=(n-1)/S+1;
	for(int i=1;i<=B;i++){
		L[i]=S*(i-1)+1;
		R[i]=min(S*i,n);
		for(int j=L[i];j<=R[i];j++){
			pos[j]=i;
			s[i]+=a[j];
		}
	}
	for(int i=1;i<maxb;i++) pl.push_back(i);
	for(int i=1;i<=n;i++) if(!vis[i]){
		int u=i;
		vector<int> vec;
		do{
			vec.push_back(u);
			vis[u]=1;
			u=p[u];
		}while(u!=i);
		if((int)vec.size()<S) continue;
		build((vector<int>){vec.back()});
		nxt[pos2[vec.back()]]=pos2[vec.back()];
		for(int j=(int)vec.size()-2;j>=0;j--){
			build((vector<int>){vec[j]});
			nxt[pos2[vec.back()]]=pos2[vec[j]];
			nxt[pos2[vec[j]]]=pos2[vec[j+1]];
			rebuild(pos2[vec[j]]);
		}
	}
	q=readint();
	while(q--){
		int t=readint();
		if(t==1){
			int l,r;
			l=readint();
			r=readint();
			if(pos[l]==pos[r]){
				printf("%lld\n",query(l,r));
				continue;
			}
			ll ans=query(l,R[pos[l]])+query(L[pos[r]],r);
			for(int i=pos[l]+1;i<pos[r];i++) ans+=s[i];
			for(int i=1;i<maxb;i++) if(sz[i])
				ans+=tag[i]*(s2[i][pos[r]-1]-s2[i][pos[l]]);
			printf("%lld\n",ans);
		}
		else if(t==2){
			int v,x;
			v=readint();
			x=readint();
			if(pos2[v]){
				int u=pos2[v];
				do{
					tag[u]+=x;
					u=nxt[u];
				}while(u!=pos2[v]);
			}
			else{
				int u=v;
				do{
					a[u]+=x;
					s[pos[u]]+=x;
					u=p[u];
				}while(u!=v);
			}
		}
		else{
			int x,y;
			x=readint();
			y=readint();
			if(x==y) continue;
			if(!pos2[x]){
				build(x);
				nxt[pos2[x]]=pos2[x];
			}
			if(!pos2[y]){
				build(y);
				nxt[pos2[y]]=pos2[y];
			}
			swap(p[x],p[y]);
			for(int i=0;i<sz[pos2[x]]-1;i++)
				if(vec[pos2[x]][i]==x){
					split(pos2[x],i+1);
					break;
				}
			for(int i=0;i<sz[pos2[y]]-1;i++)
				if(vec[pos2[y]][i]==y){
					split(pos2[y],i+1);
					break;
				}
			swap(nxt[pos2[x]],nxt[pos2[y]]);
			rebuild(pos2[x]);
			rebuild(nxt[pos2[x]]);
			rebuild(pos2[y]);
			rebuild(nxt[pos2[y]]);
			if(sz[pos2[x]]<S) ruin(pos2[x]);
			if(pos2[y]&&sz[pos2[y]]<S) ruin(pos2[y]);
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
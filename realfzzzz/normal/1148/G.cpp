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
const int maxn=1e5+5,m=1e7+5;
int mf[m],mu[m];
vector<int> p;
int n,k;
vector<int> d[maxn];
int c[m];
void modify(int x,int k){
	for(int i:d[x]) c[i]+=k;
}
int query(int x){
	int s=0;
	for(int i:d[x]) s+=c[i]*mu[i];
	return s;
}
vector<int> vec,vec2,g[maxn];
void solve(int l,int r,vector<int> p){
	if(l==r){
		g[r].push_back(vec[r]);
		for(int i:p) g[r].push_back(i);
		return;
	}
	int mid=l+(r-l)/2;
	for(int i=l;i<=mid;i++) modify(vec[i],1);
	vector<int> p1,p2;
	for(int i:p)
		if(query(i)) p1.push_back(i);
		else p2.push_back(i);
	for(int i=l;i<=mid;i++) modify(vec[i],-1);
	solve(l,mid,p1);
	solve(mid+1,r,p2);
}
int ord[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	mu[1]=1;
	for(int i=2;i<m;i++){
		if(!mf[i]){
			mf[i]=i;
			mu[i]=-1;
			p.push_back(i);
		}
		for(int j:p){
			if(i*j>=m) break;
			mf[i*j]=j;
			if(i%j==0) break;
			else mu[i*j]=-mu[i];
		}
	}
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		int a=read();
		d[i].push_back(1);
		for(int j=0;a>1;j++){
			for(int k=0;k<(1<<j);k++)
				d[i].push_back(d[i][k]*mf[a]);
			while(a/mf[a]%mf[a]==0) a/=mf[a];
			a/=mf[a];
		}
	}
	for(int i=1;i<=n;i++)
		if(!query(i)){
			vec.push_back(i);
			modify(i,1);
		}
		else vec2.push_back(i);
	int m=vec.size();
	if(m>=k){
		for(int i=0;i<k;i++)
			printf("%d ",vec[i]);
		return 0;
	}
	memset(c,0,sizeof(c));
	solve(0,m-1,vec2);
	for(int i=0;i<m;i++) ord[i]=i;
	sort(ord,ord+m,[](int a,int b){
		return g[a].size()<g[b].size();
	});
	int mx=ord[m-1];
	vector<int> ans;
	if((int)g[mx].size()>=k)
		for(int i=0;i<k;i++)
			ans.push_back(g[mx][i]);
	else for(int i=0;i<m;i++){
		int u=ord[i];
		if(g[u].size()==1) continue;
		for(int j:g[u]) ans.push_back(j);
		if((int)(ans.size()+g[mx].size())>=k){
			if(k-ans.size()==1){
				int c=g[u].size()>2?1:2;
				while(c--) ans.pop_back();
			}
			int s=ans.size();
			for(int j=0;j<k-s;j++)
				ans.push_back(g[mx][j]);
			break;
		}
	}
	for(int i:ans) printf("%d ",i);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,ans;
char a[200005];
int len[400005],v[400005],rt[400005];
int f[400005],nt[400005];
vector<int> to[400005];
namespace sgt{
	int cnt,l[10000001],r[10000001],s[10000001];
	inline void insert(int &i,int lf,int rf,int x){
		i=++cnt,s[i]=1;
		if(lf==rf) return;
		int mid=(lf+rf)>>1;
		if(x<=mid) insert(l[i],lf,mid,x);
		else insert(r[i],mid+1,rf,x);
	}
	inline int merge(int i,int j){
		if(i==0||j==0) return i|j;
		int x=++cnt;
		s[x]=s[i]+s[j];
		l[x]=merge(l[i],l[j]),r[x]=merge(r[i],r[j]);
		return x;
	}
	inline int query(int i,int lf,int rf,int x,int y){
		if(lf>y||rf<x||!i) return 0;
		if(x<=lf&&y>=rf) return s[i];
		int mid=(lf+rf)>>1;
		return query(l[i],lf,mid,x,y)+query(r[i],mid+1,rf,x,y);
	}
}
namespace tr{
	inline void dfs1(int i){
		if(v[i]){
			sgt::insert(rt[i],1,n,v[i]);
			return;
		}
		for(int j:to[i]){
			dfs1(j);
			rt[i]=sgt::merge(rt[i],rt[j]);
			v[i]=v[j];
		}
	}
	inline void dfs2(int i,int fa){
		if(nt[fa]==0||sgt::query(rt[nt[fa]],1,n,v[i],v[i]+len[i]-len[nt[fa]])>=2) f[i]=f[fa]+(len[i]>0),nt[i]=i;
		else f[i]=f[fa],nt[i]=nt[fa];
		ans=max(ans,f[i]);
		for(int j:to[i]) dfs2(j,i);
	}
}
namespace suffix_array{
	int sa[200001],rk[200001],tp[200001],tax[200001];
	int h[200001],d[20][200001],cnt,lg2[200001];
	inline void radix_sort(int m){
		fill(tax,tax+m+1,0);
		for(int i=1;i<=n;i++) tax[rk[i]]++;
		for(int i=2;i<=m;i++) tax[i]+=tax[i-1];
		for(int i=n;i;i--) sa[tax[rk[tp[i]]]--]=tp[i];
	}
	inline void suffix_sort(){
		for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
		for(int i=1;i<=n;i++) tax[a[i]-'a'+1]++,rk[i]=a[i]-'a'+1;
		for(int i=2;i<=26;i++) tax[i]+=tax[i-1];
		for(int i=n;i;i--) sa[tax[a[i]-'a'+1]--]=i;
		for(int len=1,m=26,p=0;p<n;len<<=1,m=p){
			p=0;
			for(int i=n-len+1;i<=n;i++) tp[++p]=i;
			for(int i=1;i<=n;i++) if(sa[i]>len) tp[++p]=sa[i]-len;
			radix_sort(m);
			swap(tp,rk);
			rk[sa[1]]=p=1;
			for(int i=2;i<=n;i++)
				if(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+len]==tp[sa[i-1]+len]) rk[sa[i]]=p;
				else rk[sa[i]]=++p;
		}
	}
	inline void get_height(){
		for(int i=1,k=0;i<=n;i++){
			if(k) k--;
			while(a[i+k]==a[sa[rk[i]-1]+k]) k++;
			h[rk[i]]=k,d[0][rk[i]]=rk[i];
		}
	}
	inline void doubly(){
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				if(h[d[j-1][i]]<=h[d[j-1][i+(1<<(j-1))]]) d[j][i]=d[j-1][i];
				else d[j][i]=d[j-1][i+(1<<(j-1))];
			}
		}
	}
	inline int query(int x,int y){
		int k=lg2[y-x+1];
		if(h[d[k][x]]<=h[d[k][y-(1<<k)+1]]) return d[k][x];
		return d[k][y-(1<<k)+1];
	}
	inline int dfs(int l,int r){
		int i=++cnt;
		if(l==r){
			len[i]=n-sa[l]+1,v[i]=sa[l];
			return i;
		}
		int tp=query(l+1,r);
		len[i]=h[tp];
		to[i].push_back(dfs(l,tp-1)),to[i].push_back(dfs(tp,r));
		return i;
	}
	inline void build(){
		suffix_sort();
		get_height();
		doubly();
		dfs(1,n);
	}
}
int main(){
	scanf("%d%s",&n,a+1);
	suffix_array::build();
	tr::dfs1(1),tr::dfs2(1,0);
	cout<<ans;
}
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
const int maxn=200+5;
int n,p[maxn],q[maxn],cnt,no[maxn];
bool vis[maxn];
int fa[maxn];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int s1[maxn],s2[maxn],s3[maxn];
bool check(int k){
	for(int i=1;i<=n;i++) s1[i]=s2[i]=s3[i]=0;
	for(int i=1;i<k;i++)
		if(q[i]<p[q[i+1]]) s1[q[i]]++;
		else if(q[i]>p[q[i+1]]) s2[q[i]]++;
		else s3[q[i]]++;
	for(int i=2;i<=n;i++){
		s1[i]+=s1[i-1];
		s2[i]+=s2[i-1];
		s3[i]+=s3[i-1];
	}
	for(int i=1;i<k;i++)
		if(q[i]<p[q[i+1]]){
			if(s1[p[q[i+1]]-1]-s1[q[i]-1]>1) return 0;
			if(s3[p[q[i+1]]]>s3[q[i]-1]) return 0;
		}
		else if(q[i]>p[q[i+1]]){
			if(s2[q[i]]-s2[p[q[i+1]]]>1) return 0;
			if(s3[q[i]]>s3[p[q[i+1]]-1]) return 0;
		}
	for(int i=1;i<=n;i++) s3[i]=0;
	for(int i=1;i<k;i++)
		if(q[i]<p[q[i+1]]){
			s3[q[i]]++;
			s3[p[q[i+1]]]--;
		}
		else if(q[i]>p[q[i+1]]){
			s3[p[q[i+1]]]++;
			s3[q[i]]--;
		}
	for(int i=2;i<=n;i++) s3[i]+=s3[i-1];
	for(int i=1;i<=cnt;i++) fa[i]=i;
	for(int i=1;i<n;i++) if(s3[i]){
		if(find(no[i])==find(no[i+1])) return 0;
		fa[fa[no[i]]]=no[i+1];
	}
	for(int i=1;i<=n;i++) s1[i]=s2[i]=0;
	for(int i=1;i<k;i++)
		if(q[i]<p[q[i+1]]){
			s1[q[i]]++;
			s2[p[q[i+1]]]++;
		}
		else if(q[i]>p[q[i+1]]){
			s1[p[q[i+1]]]++;
			s2[q[i]]++;
		}
	for(int i=1;i<n;i++)
		if(s3[i]==2&&!s1[i]&&!s2[i]) return 0;
	for(int i=1;i<=n;i++) s3[i]=0;
	for(int i=1;i<k;i++)
		if(q[i]==p[q[i+1]]) s3[q[i]]=1;
	for(int i=1;i<=cnt;i++) fa[i]=i;
	for(int i=1;i<n;i++)
		if(s2[i]<2&&s1[i+1]<2&&!s3[i]&&!s3[i+1])
			fa[find(no[i])]=find(no[i+1]);
	for(int i=2;i<=cnt;i++)
		if(find(i)!=find(1)) return 0;
	return 1;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) p[i]=read();
		for(int i=1;i<=n;i++) no[i]=0;
		cnt=0;
		for(int i=1;i<=n;i++) if(!no[i]){
			int u=i;
			cnt++;
			do no[u=p[u]]=cnt;while(u!=i);
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		vis[q[1]=1]=1;
		for(int i=2;i<=n;i++){
			q[i]=1;
			while(vis[q[i]]||!check(i)) q[i]++;
			vis[q[i]]=1;
		}
		for(int i=1;i<=n;i++) printf("%d ",q[i]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
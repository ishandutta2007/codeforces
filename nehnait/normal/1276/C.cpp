#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 400005
typedef pair<int,int> pii;
#define fi first
#define se second
int n;map<int,int>cc;set<pii>st;
int v[MN],b[MN],s[MN],t;
vector<int>z[MN];
int main(){int x;
	scanf("%d",&n);
	F(i,1,n)scanf("%d",&x),++cc[x];
	for(auto p:cc)st.insert({p.se,p.fi});
	for(auto p:st)v[++t]=p.se,b[t]=p.fi;
	F(i,1,t)s[i]=s[i-1]+b[i];
//	F(i,1,t)printf("(%d,%d)\n",v[i],b[i]);
	int ans=0,p=-1;
	for(int i=1;i*i<=n;++i){
		int c=upper_bound(b+1,b+t+1,i)-b-1;
		int a=s[c]+(t-c)*i;
		a=a/i*i;
		if(a/i>=i&&ans<a)ans=a,p=i;
	}printf("%d\n",ans);
	printf("%d %d\n",p,ans/p);
	F(i,1,p)z[i].resize(ans/p+1);
	F(i,1,t)b[i]=min(b[i],p);
	reverse(b+1,b+t+1),reverse(v+1,v+t+1);
	int left=ans;
	F(i,1,t)b[i]=min(b[i],left),left-=b[i];
//	F(i,1,t)printf("(%d,%d)\n",v[i],b[i]);
	int nowi=1,nowj=1;
	F(i,1,t){
		F(k,1,b[i]){
			z[nowi][(nowj+nowi-2)%(ans/p)+1]=v[i];
			if(nowi==p)nowi=1,++nowj;
			else ++nowi;
		}
	}
	F(i,1,p){F(j,1,ans/p)printf("%d ",z[i][j]);puts("");}
	return 0;
}
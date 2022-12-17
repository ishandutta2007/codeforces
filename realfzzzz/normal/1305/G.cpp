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
const int maxn=(1<<18)+5;
int n,c[maxn],fa[maxn],s[maxn];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	c[0]=1;
	ll ans=0;
	while(n--){
		int a=read();
		ans-=a;
		c[a]++;
	}
	for(int i=0;i<(1<<18);i++){
		fa[i]=i;
		s[i]=1;
	}
	for(int i=(1<<18)-1;i>=0;i--)
		for(int j=i;;j=(j-1)&i){
			if(c[j]&&c[i^j]){
				int x=find(j),y=find(i^j);
				if(x==y){
					if(j) continue;
					else break;
				}
				ans+=1ll*i*(c[j]+c[i^j]-1);
				c[j]=c[i^j]=1;
				if(s[x]<s[y]) swap(x,y);
				fa[y]=x;
				s[x]+=s[y];
			}
			if(!j) break;
		}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
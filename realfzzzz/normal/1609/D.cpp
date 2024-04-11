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
const int maxn=1e3+5;
int n,d,fa[maxn],s1[maxn],s2[maxn];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	d=readint();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		s1[i]=1;
	}
	while(d--){
		int x,y;
		x=find(readint());
		y=find(readint());
		if(x==y) s2[x]++;
		else{
			s1[x]+=s1[y];
			s2[x]+=s2[y]+1;
			fa[y]=x;
		}
		int ans=0,res=1;
		for(int i=1;i<=n;i++)
			if(fa[i]==i&&s1[i]<=s2[i]) res+=s2[i]-s1[i]+1;
		vector<int> vec;
		for(int i=1;i<=n;i++) if(fa[i]==i) vec.push_back(s1[i]);
		sort(vec.begin(),vec.end(),greater<int>());
		for(int i=0;i<min(res,(int)vec.size());i++) ans+=vec[i];
		printf("%d\n",ans-1);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
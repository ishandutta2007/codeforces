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
const int maxn=2e5+5;
int n,a[maxn];
vector<int> vec[maxn];
int p[maxn],p2[maxn],fa[maxn];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++)
			vector<int>().swap(vec[i]);
		if(n%2==1)
			vec[a[(n+1)/2]].push_back((n+1)/2);
		for(int i=1;i<=n;i++)
			if(i*2-1!=n) vec[a[i]].push_back(i);
		for(int i=1;i<=n;i++) fa[i]=i;
		int c=1;
		if(n%2==1){
			while(vec[c].size()%2==0) c++;
			if(vec[c].size()==1&&a[(n+1)/2]==c){
				printf("NO\n");
				continue;
			}
			p[(n+1)/2]=fa[(n+1)/2]=vec[c].back();
			vec[c].pop_back();
			c=1;
		}
		for(int i=1;i<=n/2;i++){
			while(!vec[c].size()) c++;
			if(vec[c].size()==1){
				c=-1;
				break;
			}
			merge(i,p[i]=vec[c].back());
			vec[c].pop_back();
			merge(n-i+1,p[n-i+1]=vec[c].back());
			vec[c].pop_back();
		}
		if(c<0){
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n/2;i++)
			if(find(i)!=find(n-i+1)){
				merge(i,n-i+1);
				swap(p[i],p[n-i+1]);
			}
		vector<int> vec;
		for(int i=1;i<=n;i++)
			if(fa[i]==i) vec.push_back(i);
		for(int i=1;i<=n;i++) p2[i]=p[i];
		if(vec.size()>1){
			for(int i=0;i<(int)vec.size()-1;i++){
				p2[vec[i]]=p[n-vec[i+1]+1];
				p2[n-vec[i]+1]=p[vec[i+1]];
			}
			p2[vec.back()]=p[vec[0]];
			p2[n-vec.back()+1]=p[n-vec[0]+1];
		}
		printf("YES\n");
		for(int i=1;i<=n;i++) printf("%d ",p2[i]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
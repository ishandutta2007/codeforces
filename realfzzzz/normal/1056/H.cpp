#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=3e5+5;
int n,q,k[maxn];
vector<int> c[maxn];
int p[maxn],t[maxn];
vector<pair<int,int>> g[maxn];
const int S=350;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		q=readint();
		for(int i=1;i<=q;i++){
			c[i].resize(k[i]=readint());
			for(int j=0;j<k[i];j++) c[i][j]=readint();
		}
		bool flag=1;
		for(int i=1;i<=n;i++) p[i]=-1;
		for(int i=1;i<=q;i++) if(k[i]>S){
			for(int j=0;j<k[i];j++){
				p[c[i][j]]=j;
				if(j<k[i]-1) t[c[i][j]]=c[i][j+1];
			}
			for(int j=1;j<=q;j++){
				int mx=p[c[j][k[j]-1]];
				for(int h=k[j]-2;h>=0;h--) if(p[c[j][h]]>=0){
					if(mx>p[c[j][h]]&&t[c[j][h]]!=c[j][h+1]) flag=0;
					mx=max(mx,p[c[j][h]]);
				}
			}
			for(int j=0;j<k[i];j++) p[c[i][j]]=-1;
		}
		for(int i=1;i<=n;i++) vector<pair<int,int>>().swap(g[i]);
		for(int i=1;i<=q;i++) if(k[i]<=S)
			for(int j=0;j<k[i]-1;j++)
				for(int h=j+1;h<k[i];h++)
					g[c[i][j]].push_back({c[i][h],c[i][j+1]});
		for(int i=1;i<=n;i++){
			for(auto j:g[i]){
				int x=j.first;
				if(p[x]>=0&&p[x]!=j.second) flag=0;
				p[x]=j.second;
			}
			for(auto j:g[i]) p[j.first]=-1;
		}
		printf(flag?"Robot\n":"Human\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
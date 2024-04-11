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
const int maxn=1e5+5;
int n,p[maxn],m=0;
bool vis[maxn];
vector<int> c[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	for(int i=1;i<=n;i++) if(!vis[i]){
		int u=i;
		m++;
		do{
			vis[u]=1;
			c[m].push_back(u);
			u=p[u];
		}while(u!=i);
	}
	for(int i=1;i<=m;i++) if((int)c[i].size()==1){
		printf("YES\n");
		for(int j=1;j<=n;j++) if(c[i][0]!=j) printf("%d %d\n",c[i][0],j);
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=m;i++) flag&=c[i].size()%2==0;
	if(!flag){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=m;i++) if((int)c[i].size()==2){
		printf("YES\n%d %d\n",c[i][0],c[i][1]);
		for(int j=1;j<=m;j++) if(i!=j)
			for(int k=0;k<(int)c[j].size();k+=2)
				printf("%d %d\n%d %d\n",c[i][0],c[j][k],c[i][1],c[j][k+1]);
		return 0;
	}
	printf("NO\n");
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
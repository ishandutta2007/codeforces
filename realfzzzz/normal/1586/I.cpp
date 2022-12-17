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
const int maxn=2e3+5;
int n;
char g[maxn][maxn];
struct pnt{
	int x,y;
	bool f;
};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	if(n%2==1){
		printf("NONE\n");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%s",g[i]+1);
	bool flag=1;
	for(int i=1;i<=n/2;i++){
		vector<pnt> vec;
		for(int j=1;j<=i*2-1;j++){
			vec.push_back({i*2-j,j,(bool)(j%2)});
			vec.push_back({n-i*2+j+1,n-j+1,(bool)(j%2)});
		}
		for(int j=1;j<=n-i*2+1;j++){
			vec.push_back({i*2+j-1,j,(bool)(j%2)});
			vec.push_back({n-i*2-j+2,n-j+1,(bool)(j%2)});
		}
		int c=-1;
		for(pnt p:vec) if(g[p.x][p.y]!='.'){
			if(c>=0&&c!=((g[p.x][p.y]=='S')^p.f)){
				printf("NONE\n");
				return 0;
			}
			c=(g[p.x][p.y]=='S')^p.f;
		}
		if(c<0) flag=0;
		else for(pnt p:vec) g[p.x][p.y]=(c^p.f)?'S':'G';
	}
	if(flag){
		printf("UNIQUE\n");
		for(int i=1;i<=n;i++) printf("%s\n",g[i]+1);
	}
	else printf("MULTIPLE\n");
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
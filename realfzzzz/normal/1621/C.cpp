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
const int maxn=1e4+5;
int n,p[maxn];
int main(){
	#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) p[i]=0;
		for(int i=1;i<=n;i++) if(!p[i]){
			printf("? %d\n",i);
			fflush(stdout);
			int x=readint(),u=x;
			do{
				printf("? %d\n",i);
				fflush(stdout);
				p[u]=readint();
				u=p[u];
			}while(u!=x);
		}
		printf("! ");
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		printf("\n");
		fflush(stdout);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
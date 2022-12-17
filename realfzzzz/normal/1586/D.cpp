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
const int maxn=100+5;
int n,p[maxn];
int main(){
	/*
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	*/
	n=readint();
	int x=1;
	for(;x<n;x++){
		printf("? ");
		for(int i=1;i<n;i++) printf("1 ");
		printf("%d\n",x+1);
		fflush(stdout);
		int res=readint();
		if(res) p[res]=x;
		else break;
	}
	for(int i=1;i<=n-x;i++){
		printf("? ");
		for(int j=1;j<n;j++) printf("%d ",i+1);
		printf("1\n");
		fflush(stdout);
		p[readint()]=-i;
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",n-x+p[i]+1);
	printf("\n");
	fflush(stdout);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
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
mt19937 rnd(time(0)^20060122);
char s[10];
bool query(int l,int r){
	printf("? %d %d\n",r-l+1,r-l+1);
	for(int i=1;i<=r-l+1;i++) printf("%d ",i);
	printf("\n");
	for(int i=l;i<=r;i++) printf("%d ",i);
	printf("\n");
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='F';
}
int main(){
	#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		int n=readint();
		readint();
		int x=1;
		for(int i=0;i<20;i++){
			int y=rnd()%n+1;
			while(x==y) y=rnd()%n+1;
			printf("? 1 1\n%d\n%d\n",x,y);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='S') x=y;
		}
		if(x!=1){
			printf("? 1 1\n1\n%d\n",x);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='S'){
				printf("! 1\n");
				fflush(stdout);
				continue;
			}
		}
		int k=0;
		while((2<<k)<=n&&!query((1<<k)+1,2<<k)) k++;
		int l=(1<<k)+1,r=min(2<<k,n);
		while(l<r){
			int mid=l+(r-l)/2;
			if(query(l,mid)) r=mid;
			else l=mid+1;
		}
		printf("! %d\n",r);
		fflush(stdout);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
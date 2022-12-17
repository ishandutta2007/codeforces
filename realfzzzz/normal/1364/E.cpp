//test
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cstdio>
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
const int maxn=(1<<11)+5;
int n,ord[maxn],p[maxn];
int main(){
	/*
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	*/
	srand(time(0));
	n=readint();
	for(int i=1;i<=n;i++) ord[i]=i;
	random_shuffle(ord+1,ord+n+1);
	int a=ord[1],b=ord[2],x;
	printf("? %d %d\n",a,b);
	fflush(stdout);
	x=readint();
	for(int i=3;i<=n;i++){
		printf("? %d %d\n",a,ord[i]);
		fflush(stdout);
		int res=readint();
		if(res<x){
			b=ord[i];
			x=res;
		}
		else if(res==x){
			a=ord[i];
			printf("? %d %d\n",a,b);
			fflush(stdout);
			x=readint();
		}
	}
	while(1){
		int c=rand()%n+1,x,y;
		if(a==c||b==c) continue;
		printf("? %d %d\n",a,c);
		fflush(stdout);
		x=readint();
		printf("? %d %d\n",b,c);
		fflush(stdout);
		y=readint();
		if(x!=y){
			if(y<x) a=b;
			break;
		}
	}
	p[a]=0;
	for(int i=1;i<=n;i++) if(i!=a){
		printf("? %d %d\n",i,a);
		fflush(stdout);
		p[i]=readint();
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	printf("\n");
	return 0;
}
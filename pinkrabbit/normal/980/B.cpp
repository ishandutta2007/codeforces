#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,q;
int a[100001];

int h[100001],nxt[200001],to[200001],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d%d",&n,&q);
	puts("YES");
	if(q%2){
		F(i,1,n) printf("."); puts("");
		if(q<=n-2){
			F(i,1,(n-q)/2) printf(".");
			F(i,1,q) printf("#");
			F(i,1,(n-q)/2) printf("."); puts("");
			F(i,1,n) printf("."); puts("");
			F(i,1,n) printf("."); puts("");
			return 0;
		}
		else{
			printf(".");
			F(i,1,n-2) printf("#");
			printf("."); puts("");
			q-=n-2;
			printf(".");
			F(i,1,q/2) printf("#");
			F(i,1,n-2-q) printf(".");
			F(i,1,q/2) printf("#");
			puts(".");
			F(i,1,n) printf("."); puts("");
		}
	}
	else{
		F(i,1,n) printf("."); puts("");
		printf(".");
		F(i,1,q/2) printf("#");
		F(i,1,n-1-q/2) printf(".");
		puts("");
		printf(".");
		F(i,1,q/2) printf("#");
		F(i,1,n-1-q/2) printf(".");
		puts("");
		F(i,1,n) printf("."); puts("");
	}
	return 0;
}
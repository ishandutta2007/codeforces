#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n;
int zt[20];
int main(){
	scanf("%d",&n);
	For(i,n){
		char ch; int x;
		while((ch=getchar())!='|'&&ch!='&'&&ch!='^');
		scanf("%d",&x);
//		printf("%c %d\n",ch,x);
		if(ch=='|'){
			F(j,0,9) if(x>>j&1) zt[j]=2;
		}
		else if(ch=='&'){
			F(j,0,9) if((x>>j&1)==0) zt[j]=3;
		}
		else if(ch=='^'){
			F(j,0,9) if(x>>j&1) zt[j]^=1;
		}
	}
//	F(j,0,9) printf("%d ",zt[j]);
	puts("3");
	int x;
	printf("| "); x=0;
	F(j,0,9) if(zt[j]==2) x|=(1<<j);
	printf("%d\n",x);
	printf("& "); x=1023;
	F(j,0,9) if(zt[j]==3) x^=(1<<j);
	printf("%d\n",x);
	printf("^ "); x=0;
	F(j,0,9) if(zt[j]==1) x|=(1<<j);
	printf("%d\n",x);
	return 0;
}
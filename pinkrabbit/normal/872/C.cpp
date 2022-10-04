#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
inline int Min(int p,int q){return p<q?p:q;}
inline int Max(int p,int q){return p>q?p:q;}
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		switch(n%4){
			case 0: printf("%d\n",n/4);break;
			case 1: {n>=9?printf("%d\n",(n-9)/4+1):puts("-1");break;}
			case 2: {n>=6?printf("%d\n",(n-6)/4+1):puts("-1");break;}
			case 3: {n>=15?printf("%d\n",(n-15)/4+2):puts("-1");break;}
		}
	}
	return 0;
}
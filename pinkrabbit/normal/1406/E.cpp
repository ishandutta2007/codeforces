#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
bool ip[MN];
int p[MN],pc;
inline void sieve(int n){
	F(i,2,n){
		if(!ip[i])p[++pc]=i;
		for(int j=1,k;j<=pc;++j){
			if((k=p[j]*i)>n)break;
			ip[k]=1;
			if(i%p[j]==0)break;
		}
	}
//	F(i,1,pc)printf("%d,",p[i]);puts("");
}
int n,buk[MN],sum;
int main(){
	int ans=1;
	scanf("%d",&n);
	sieve(n);
	if(n==1)return printf("C 1\n"),0;
	F(i,1,n)buk[i]=1;
	sum=n;
	int S=sqrt(n);
	//[>S]
	int c=1;
	while(c<=pc&&p[c]<=S)++c;
	if(c<=pc){
		int B=sqrt(pc-c+1);
		int lst=0;
		F(i,0,pc-c){
			int x=p[c+i];
			printf("B %d\n",x),fflush(stdout),scanf("%*d");
			F(j,1,n/x)if(buk[x*j])buk[x*j]=0,--sum;
			if(i%B==B-1||i==pc-c){
				printf("A 1\n"),fflush(stdout);
				int val;
				scanf("%d",&val);
				if(val!=sum){
					F(j,lst,i){
						printf("A %d\n",p[c+j]),fflush(stdout);
						int val2;
						scanf("%d",&val2);
						if(val2){
							ans*=p[c+j];
							break;
						}
					}
					break;
				}
				lst=i+1;
			}
		}
	}
	F(i,1,c-1){
		int x=p[i],k=0;
		for(int z=x;z<=n;z*=x)++k;
		dF(j,k,1){
			int y=1;
			F(o,1,j)y*=x;
			printf("B %d\n",y),fflush(stdout),scanf("%*d");
			printf("A %d\n",y),fflush(stdout);
			int val;
			scanf("%d",&val);
			if(val){
				ans*=y;
				break;
			}
		}
	}
	printf("C %d\n",ans);
	return 0;
}
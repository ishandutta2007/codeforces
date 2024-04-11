#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,q;
char str[105];
int k[105];
int fk[105][105];

int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n){
		scanf("%s",str+1);
		int cnt=0;
		F(j,1,n){
			if(str[j]=='.') ++cnt;
			else cnt=0;
			if(cnt>=q){
				F(l,j-q+1,j) ++fk[i][l];
			}
		}
		F(j,1,n){
			if(str[j]=='.') ++k[j];
			else k[j]=0;
			if(k[j]>=q){
				F(l,i-q+1,i) ++fk[l][j];
			}
		}
	}
	int a1=1,a2=1;
	F(i,1,n) F(j,1,n) if(fk[a1][a2]<fk[i][j]) a1=i,a2=j;
	printf("%d %d",a1,a2);
	return 0;
}
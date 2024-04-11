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
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
char a[999][999];
int b[999],c[999];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n)F(j,1,n)if(a[i][j]=='E')++b[i],++c[j];
	int x=0,y=0;
	F(i,1,n)x=max(x,b[i]),y=max(y,c[i]);
	if(x==n&&y==n)return puts("-1"),0;
	if(x!=n){
		F(i,1,n){
			int p=0;
			F(j,1,n)if(a[i][j]=='.')p=j;
			printf("%d %d\n",i,p);
		}
	}
	else{
		F(i,1,n){
			int p=0;
			F(j,1,n)if(a[j][i]=='.')p=j;
			printf("%d %d\n",p,i);
		}
	}
	return 0;
}
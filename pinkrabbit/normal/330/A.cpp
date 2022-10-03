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
char a[100][100];
int b[100],c[100];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n)F(j,1,m)if(a[i][j]=='S')b[i]=c[j]=1;
	int B=0,C=0;
	F(i,1,n)B+=b[i];
	F(i,1,m)C+=c[i];
	printf("%d\n",n*m-B*C);
	return 0;
}
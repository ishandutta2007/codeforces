#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int A[MN][MN];
int S[4][4]={8,9,1,13,3,12,7,5,0,2,4,11,6,10,15,14};
int main(){
	scanf("%d",&n);
	F2(a,0,n/4)F2(b,0,n/4)F2(i,0,4)F2(j,0,4)A[4*a+i][4*b+j]=4*n*a+16*b+S[i][j];
	F2(i,0,n){F2(j,0,n)printf("%d ",A[i][j]);puts("");}
	return 0;
}
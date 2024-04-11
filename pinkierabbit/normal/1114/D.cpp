#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
typedef long long LL;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

int n,q,m,k;
int a[300005],b[300005];
int f[5005][5005];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	n=unique(a+1,a+n+1)-a-1;
//	F(i,1,n)printf("%d,",a[i]);puts("");
	a[n+1]=-1;
	f[1][n]=0;
	dF(q,n-1,1){
		F(i,1,n-q+1){
			int j=i+q-1;
			f[i][j]=max(f[i-1][j],f[i][j+1]);
			if(a[i-1]==a[j+1])f[i][j]=max(f[i][j],f[i-1][j+1]+1);
		}
	}
	int ans=0;
	F(i,1,n)ans=max(ans,f[i][i]);
	printf("%d\n",n-1-ans);
	return 0;
}
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
int n;
int a[MN],b[MN][10],c[MN][10],d[10];
int e[10],f[10],g[10][MN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		F(i,0,9)d[i]=0,e[i]=n+1,f[i]=0;
		F(i,1,n)F(j,0,9)g[j][i]=0;
		F(i,1,n)scanf("%1d",a+i),++d[a[i]],g[a[i]][i]=1;
		a[0]=a[n+1]=-1;
		F(i,0,n+1)F(j,0,9)b[i][j]=c[i][j]=0;
		F(i,1,n+1)F(j,0,9)F(k,0,j)b[i][j]=max(b[i][j],b[i-1][k]+(a[i]==j));
		dF(i,n,0)F(j,0,9)F(k,j,9)c[i][j]=max(c[i][j],c[i+1][k]+(a[i]==j));
		dF(i,n,1)F(j,0,a[i])e[j]=i;
		F(i,1,n)F(j,a[i],9)f[j]=i;
		F(j,0,9)F(i,1,n+1)g[j][i]+=g[j][i-1];
//		F(j,0,9)printf("%2d%c",b[n+1][j]," \n"[j==9]);
//		F(j,0,9)printf("%2d%c",d[j]," \n"[j==9]);
//		F(j,0,9)printf("%2d%c",c[0][j]," \n"[j==9]);
		int ok=0;
		F(j,0,8)if(b[n+1][j]+c[0][j+1]==n){
//			printf("\t\t\t%d\n",j);
			F(i,1,n)printf("%d",a[i]<=j?1:2);
			puts("");
			ok=1;break;
		}
		if(ok)continue;
		F(j,1,8)if(b[n+1][j-1]+d[j]+c[0][j+1]==n&&g[j][f[j-1]]-g[j][e[j+1]]<=0){
//			printf("\t\t\t%d\n",j);
			F(i,1,n)printf("%d",a[i]<j?1:a[i]>j?2:i<=e[j+1]?2:1);
			puts("");
			ok=1;break;
		}
		if(ok)continue;
		puts("-");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=510;
int cnt[N*N],a[N][N],n,k,s[N][N],L[N*N],R[N*N],U[N*N],D[N*N];
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,n)rep(j,n)scanf("%d",&a[i][j]),cnt[a[i][j]]++;
	int num=0;
	rep(i,n*n)if(cnt[i])num++;
	if(num<=k){printf("%d\n",k-num);return 0;}
	rep(i,n*n)U[i]=L[i]=n;
	rep(i,n)rep(j,n)U[a[i][j]]=min(U[a[i][j]],i),D[a[i][j]]=max(D[a[i][j]],i),L[a[i][j]]=min(L[a[i][j]],j),R[a[i][j]]=max(R[a[i][j]],j);
	// rep(i,n*n)if(D[i])printf("%d %d %d %d %d\n",i,U[i],D[i],L[i],R[i]);
	rep(len,n)
	{
		rep(i,n-len+1)rep(j,n-len+1)s[i][j]=0;
		rep(i,n*n)
		{
			if(!R[i]||max(D[i]-U[i]+1,R[i]-L[i]+1)>len)continue;
			int x=max(1,D[i]-len+1),y=max(1,R[i]-len+1);
			// printf("%d %d %d %d %d\n",i,x,y,U[i],L[i]);
			s[x][y]++;
			s[U[i]+1][y]--;
			s[x][L[i]+1]--;
			s[U[i]+1][L[i]+1]++;
		}
		rep(i,n-len+1)rep(j,n-len+1)s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		// if(len==1)rep(i,n-len+1)rep(j,n-len+1)printf("%d %d %d\n",i,j,s[i][j]);
		rep(i,n-len+1)rep(j,n-len+1)if(num-s[i][j]==k||num-s[i][j]==k-1){puts("1");return 0;}
	}
	puts("2");
    return 0;
}
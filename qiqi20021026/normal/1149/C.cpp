#include<bits/stdc++.h>

using namespace std;

#define N 1200000
#define ls (x<<1)
#define rs (x<<1|1)

int n,m,a[N],A[N],L[N][2],R[N][2],f[N],sum[N][2];
char s[N];

void mdf(int x,int l,int r,int t){
	if (l==r){
		if (a[t]){
			f[x]=1;
			sum[x][0]=1; sum[x][1]=-1;
			A[x]=1;
			R[x][0]=R[x][1]=1;
			L[x][0]=1; L[x][1]=0;
		}
		else{
			f[x]=1;
			sum[x][0]=-1; sum[x][1]=1;
			A[x]=1;
			R[x][0]=0; R[x][1]=1;
			L[x][0]=L[x][1]=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (t<=mid) mdf(ls,l,mid,t);
	else mdf(rs,mid+1,r,t);
	sum[x][0]=sum[ls][0]+sum[rs][0];
	sum[x][1]=sum[ls][1]+sum[rs][1];
	f[x]=max(max(f[ls],f[rs]),max(R[ls][0]+L[rs][0],R[ls][1]+L[rs][1]));
	A[x]=max(A[ls]+sum[rs][1],sum[ls][0]+A[rs]);
	R[x][0]=max(R[rs][0],R[ls][0]+sum[rs][0]);
	R[x][1]=max(R[rs][1],max(R[ls][0]+A[rs],R[ls][1]+sum[rs][1]));
	L[x][0]=max(L[ls][0],max(L[rs][1]+A[ls],L[rs][0]+sum[ls][0]));
	L[x][1]=max(L[ls][1],L[rs][1]+sum[ls][1]);
}

int main(){
	scanf("%d%d%s",&n,&m,s+1); n*=2; n-=2;
	for (int i=1;i<=n;++i) a[i]=s[i]==')';
	for (int i=1;i<=n;++i) mdf(1,1,n,i);
	printf("%d\n",f[1]);
	while (m--){
		int x,y; scanf("%d%d",&x,&y);
		swap(a[x],a[y]);
		mdf(1,1,n,x); mdf(1,1,n,y);
		printf("%d\n",f[1]);
	}
	
	return 0;
}
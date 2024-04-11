#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 1005
int n,a[MN],ans[MN][MN];
int bl[MN],br[MN],tp;
int sg[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	tp=1,bl[1]=1,br[1]=n+1;
	F(i,1,n){
		int p=0,s=0;
		F(j,1,tp)if(j==tp||s+br[j]-bl[j]+1>=a[i]){p=j;break;}else s+=br[j]-bl[j]+1;
		int z=(s+br[p]-bl[p]+1>a[i])?a[i]-s:br[p]-bl[p];
		F(j,1,p-1)F(k,bl[j],br[j])ans[k][i]=1;
		int l=bl[p],r=br[p];
		F(j,p+1,tp)bl[j-1]=bl[j],br[j-1]=br[j];
		--tp;
		F(k,l,l+z-1)ans[k][i]=1;
		int lf=a[i]-s-z;
		F(k,1,n+1)if(lf&&sg[k])ans[k][i]=1,--lf;
		if(lf)F(k,1,n)if((k<l||k>r)&&!ans[k][i]){ans[k][i]=1;break;}
		if(z>1){
			bl[++tp]=l;
			br[tp]=l+z-1;
		}else sg[l]=1;
		if(r-l+1-z>1){
			bl[++tp]=l+z;
			br[tp]=r;
		}else sg[r]=1;
	}
	printf("%d\n",n+1);
	F(i,1,n+1){F(j,1,n)printf("%d",ans[i][j]);puts("");}
	return 0;
}
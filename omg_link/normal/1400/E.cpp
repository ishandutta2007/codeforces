#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#define MN 5000
typedef long long LL;

int n,a[MN+5];

std::map<int,int> rk;
int ark[MN+5],rkc=0;

LL f[MN+5][MN+5];
//f[i][j] : ij 

LL ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		rk[a[i]]=0;
	}
	for(auto &x:rk){
		x.second = (++rkc);
		ark[rkc] = x.first;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0] = 0;
	for(int i=1;i<=n;i++){
		LL bst = f[i-1][0];
		for(int j=0,ed=rk[a[i]];j<=ed;j++){
			bst += ark[j]-(j>0?ark[j-1]:0);
			bst = std::min(bst,f[i-1][j]);
			f[i][j] = bst+(j!=ed);
		}
		for(int j=rk[a[i]]-1;j>=0;j--){
			f[i][j] = std::min(f[i][j],f[i][j+1]);
		}
	}
	ans = n;
	for(int i=1;i<=rkc;i++)
		ans = std::min(ans,f[n][i]);
	printf("%lld\n",ans);
}
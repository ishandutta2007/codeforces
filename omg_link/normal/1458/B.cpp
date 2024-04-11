#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 100

int n,a[MN+5],b[MN+5],f[MN+5][MN*MN+5];
int tot;

int main(){
	memset(f,0xff,sizeof(f));
	scanf("%d",&n);
	f[0][0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		tot += b[i];
		f[i][0] = 0;
		for(int j=n;j>=1;j--){
			for(int L=a[i];L<=i*MN;L++){
				if(f[j-1][L-a[i]]==-1) continue;
				f[j][L] = std::max(f[j][L],f[j-1][L-a[i]]+b[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int L=0;L<=n*MN;L++){
			if(f[i][L]==-1) continue;
			ans = std::max(ans,std::min(tot+f[i][L],2*L));
		}
		printf("%d%s\n",ans>>1,ans&1?".5000000000":".0000000000");
	}
}
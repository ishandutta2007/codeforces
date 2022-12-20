#include <stdio.h>
#include <algorithm>
#define MN 200

int R,G,B;
int r[MN+5],g[MN+5],b[MN+5];
int f[MN+5][MN+5][MN+5];
int ans=0;

int main(){
	scanf("%d%d%d",&R,&G,&B);
	for(int i=1;i<=R;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=G;i++)
		scanf("%d",&g[i]);
	for(int i=1;i<=B;i++)
		scanf("%d",&b[i]);
	std::sort(r+1,r+1+R);
	std::sort(g+1,g+1+G);
	std::sort(b+1,b+1+B);
	f[0][0][0] = 0;
	for(int cr=0;cr<=R;cr++){
		for(int cg=0;cg<=G;cg++){
			for(int cb=0;cb<=B;cb++){
				if(cr!=0 && cg!=0)
					f[cr][cg][cb] = std::max(f[cr][cg][cb],f[cr-1][cg-1][cb]+r[cr]*g[cg]);
				if(cr!=0 && cb!=0)
					f[cr][cg][cb] = std::max(f[cr][cg][cb],f[cr-1][cg][cb-1]+r[cr]*b[cb]);
				if(cg!=0 && cb!=0)
					f[cr][cg][cb] = std::max(f[cr][cg][cb],f[cr][cg-1][cb-1]+g[cg]*b[cb]);
				ans = std::max(ans,f[cr][cg][cb]);
			}
		}
	}
	printf("%d\n",ans);
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 2000
int n,k,f[MN+5][MN+5],bst=1;
bool o[MN+5][MN+5];
char c[MN+5][MN+5],ans[MN+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%s",&c[i][1]);
	memset(f,0xff,sizeof(f));
	f[0][1]=f[1][0]=k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			f[i][j]=std::max(f[i-1][j],f[i][j-1])-(c[i][j]!='a');
			if(f[i][j]>=0) bst=std::max(bst,i+j);
		}
	for(int i=2;i<=bst;i++) ans[i]='a';
	for(int i=std::max(1,bst-n),j=std::min(n,bst-1);j>=1&&i<=n;i++,j--) if(f[i][j]>=0) o[i][j]=true;
	if(bst==1) ans[2]=c[1][1],o[1][1]=true,bst++;
	for(;bst<=2*n;bst++){
		char gd=127;
		for(int i=std::max(1,bst-n),j=std::min(n,bst-1);j>=1&&i<=n;i++,j--)
			if(o[i][j]){
				if(i!=n) gd=std::min(gd,c[i+1][j]);
				if(j!=n) gd=std::min(gd,c[i][j+1]);
			}
		for(int i=std::max(1,bst-n),j=std::min(n,bst-1);j>=1&&i<=n;i++,j--)
			if(o[i][j]){
				if(i!=n&&c[i+1][j]==gd) o[i+1][j]=true;
				if(j!=n&&c[i][j+1]==gd) o[i][j+1]=true;
			}
		ans[bst+1]=gd;
	}
	ans[2*n+1]='\0';
	printf("%s",&ans[2]);
}
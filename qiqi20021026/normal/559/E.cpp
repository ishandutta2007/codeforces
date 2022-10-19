#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

int n,ans,f[120][120][2];
struct node{
	int xb,fw;
	bool operator < (const node p) const{return xb<p.xb;}
}a[120];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].xb,&a[i].fw);
	sort(a+1,a+n+1); a[0].xb=-1e9;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
			for (int k=0;k<=1;k++){
				ans=max(ans,f[i][j][k]);
				int mx=-1,x=0,y=0,tmp1=a[j].xb+a[j].fw*k;
				for (int l=i+1;l<=n;l++)
					for (int t=0;t<=1;t++){
						int tmp2=a[l].xb+a[l].fw*t;
						if (mx<tmp2){mx=tmp2; x=l; y=t;}
						f[l][x][y]=max(f[l][x][y],f[i][j][k]+mx-tmp2+min(a[l].fw,tmp2-tmp1));
					}
			}
	printf("%d\n",ans);
	
	return 0;
}
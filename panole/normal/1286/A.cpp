#include<bits/stdc++.h>
using namespace std;

int n,a[110],f[110][110][110][2],cnt[2];

void work(int i,int dj,int dk,int nw)
{
	for (int j=-dj; j<=n; j++)
		for (int k=-dk; k<=n; k++)
			for (int o=0; o<2; o++)
				if (f[i-1][j][k][o]+(o!=nw)<f[i][j+dj][k+dk][nw])
					f[i][j+dj][k+dk][nw]=f[i-1][j][k][o]+(o!=nw);
}

int main()
{
	scanf("%d",&n),cnt[0]=n/2,cnt[1]=n-cnt[0];
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		if (a[i]) cnt[a[i]&1]--;
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int k=0; k<=n; k++) f[i][j][k][0]=f[i][j][k][1]=114514;
	if (a[1]) f[1][cnt[0]][cnt[1]][a[1]&1]=0; else
	{
		if (cnt[0]) f[1][cnt[0]-1][cnt[1]][0]=0;
		if (cnt[1]) f[1][cnt[0]][cnt[1]-1][1]=0;
	}
	for (int i=2; i<=n; i++)
	{
		if (a[i]) work(i,0,0,a[i]&1); else
		work(i,-1,0,0),work(i,0,-1,1);
	}
	printf("%d\n",min(f[n][0][0][0],f[n][0][0][1]));
	return 0;
}
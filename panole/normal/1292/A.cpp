#include<bits/stdc++.h>
using namespace std;

int n,cnt,q,ans,x,y,dx[6],dy[6];
bool bo[3][200010];

int main()
{
	dx[0]=dx[1]=dx[2]=1;
	dx[3]=dx[4]=dx[5]=-1;
	dy[0]=dy[3]=1,dy[1]=dy[4]=0,dy[2]=dy[5]=-1;
	scanf("%d%d",&n,&q),cnt=0;
	memset(bo,1,sizeof(bo));
	while (q--)
	{
		scanf("%d%d",&x,&y);
		if (!bo[x][y])
		{
			for (int i=0; i<6; i++)
				if (x+dx[i]>0&&x+dx[i]<3&&y+dy[i]>0&&y+dy[i]<=n&&!bo[x+dx[i]][y+dy[i]]) cnt--;
			bo[x][y]=1;
		} else
		{
			for (int i=0; i<6; i++)
				if (x+dx[i]>0&&x+dx[i]<3&&y+dy[i]>0&&y+dy[i]<=n&&!bo[x+dx[i]][y+dy[i]]) cnt++;
			bo[x][y]=0;
		}
		if (!cnt) puts("Yes"); else puts("No");
	}
	return 0;
}
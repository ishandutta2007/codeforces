#include <bits/stdc++.h>
using namespace std;
int cnt[3][2];
int sum[3];
int mp[301][301];
int n,m,i,j,k,t,t1;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        cnt[0][0]=0;
        cnt[0][1]=0;
        cnt[1][0]=0;
        cnt[1][1]=0;
        cnt[2][0]=0;
        cnt[2][1]=0;
        for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            if (c=='X') {
			cnt[(i+j)%3][1]++; mp[i][j]=1;
			}
            else if (c=='O') {
			cnt[(i+j)%3][0]++; mp[i][j]=0;}
			else mp[i][j]=-1;
		}
			sum[0]=cnt[0][0]+cnt[0][1];
			sum[1]=cnt[1][0]+cnt[1][1];
			sum[2]=cnt[2][0]+cnt[2][1];
			if ((sum[0]>=sum[1])and(sum[0]>=sum[2]))
			{
				if (cnt[1][0]+cnt[2][1]<cnt[1][1]+cnt[2][0])
				{
					for (i=1;i<=n;i++)
					{ 
					for (j=1;j<=n;j++)
					{
						if (mp[i][j]==-1) cout<<'.';
						else if ((i+j)%3==1) cout<<'X';
						else if ((i+j)%3==2) cout<<'O';
						else if (mp[i][j]) cout<<'X';
						else cout<<'O';
					}
					cout<<endl;
					}
				}
				else
				{
					for (i=1;i<=n;i++)
					{ 
					for (j=1;j<=n;j++)
					{
						if (mp[i][j]==-1) cout<<'.';
						else if ((i+j)%3==1) cout<<'O';
						else if ((i+j)%3==2) cout<<'X';
						else if (mp[i][j]) cout<<'X';
						else cout<<'O';
					}
					cout<<endl;
					}
				}
			}
			else
			if ((sum[1]>=sum[0])and(sum[1]>=sum[2]))
			{
				if (cnt[0][0]+cnt[2][1]<cnt[0][1]+cnt[2][0])
				{
					for (i=1;i<=n;i++)
					{ 
					for (j=1;j<=n;j++)
					{
						if (mp[i][j]==-1) cout<<'.';
						else if ((i+j)%3==0) cout<<'X';
						else if ((i+j)%3==2) cout<<'O';
						else if (mp[i][j]) cout<<'X';
						else cout<<'O';
					}
					cout<<endl;
					}
				}
				else
				{
					for (i=1;i<=n;i++)
					{ 
					for (j=1;j<=n;j++)
					{
						if (mp[i][j]==-1) cout<<'.';
						else if ((i+j)%3==0) cout<<'O';
						else if ((i+j)%3==2) cout<<'X';
						else if (mp[i][j]) cout<<'X';
						else cout<<'O';
					}
					cout<<endl;
					}
				}
			}
			else
			if ((sum[2]>=sum[1])and(sum[2]>=sum[0]))
			{
				if (cnt[1][0]+cnt[0][1]<cnt[1][1]+cnt[0][0])
				{
					for (i=1;i<=n;i++)
					{ 
					for (j=1;j<=n;j++)
					{
						if (mp[i][j]==-1) cout<<'.';
						else if ((i+j)%3==1) cout<<'X';
						else if ((i+j)%3==0) cout<<'O';
						else if (mp[i][j]) cout<<'X';
						else cout<<'O';
					}
					cout<<endl;
					}
				}
				else
				{
					for (i=1;i<=n;i++)
					{ 
					for (j=1;j<=n;j++)
					{
						if (mp[i][j]==-1) cout<<'.';
						else if ((i+j)%3==1) cout<<'O';
						else if ((i+j)%3==0) cout<<'X';
						else if (mp[i][j]) cout<<'X';
						else cout<<'O';
					}
					cout<<endl;
					}
				}
			}
        
    }
}
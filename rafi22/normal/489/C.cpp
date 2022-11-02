#include <iostream>

using namespace std;

int DP[107][907];
int DP1[107][907];

int main()
{
    for(int i=0;i<103;i++)
    {
        for(int j=0;j<=903;j++)
        {
            DP[i][j]=-1;
            DP1[i][j]=1000007;
        }
    }
    int n,s;
    cin>>n>>s;
    DP[n+1][0]=0;
    DP1[n+1][0]=0;
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<=s;j++)
        {
            int l;
            if(i>1||n==1) l=0;
            else l=1;
            for(;l<=min(9,j);l++)
            {
                if(DP[i+1][j-l]>-1) DP[i][j]=max(DP[i][j],l);
                if(DP1[i+1][j-l]<10000) DP1[i][j]=min(DP1[i][j],l);
            }
        }
    }
    int s1=s;
    for(int i=1;i<=n;i++)
    {
        if(DP1[i][s]==1000007)
        {
            cout<<-1;
            break;
        }
        cout<<DP1[i][s];
        s-=DP1[i][s];
    }
    cout<<" ";
    for(int i=1;i<=n;i++)
    {
        if(DP[i][s1]==-1)
        {
            cout<<-1;
            break;
        }
        cout<<DP[i][s1];
        if(DP[i][s1]==-1) break;
        s1-=DP[i][s1];
    }

    return 0;
}
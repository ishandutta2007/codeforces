#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=55;
int n,t;
int mod=1e9+7;

long long int dp[3][nax][nax][nax];
long long int s[nax];
long long int a[nax][nax*nax];
long long int b[nax][nax][nax*nax];

long long int memo(int first,int a,int b,int c)
{
    if(a<0 || b<0 || c<0) return 0;
    if(first==0 && a==0) return 0;
    if(first==1 && b==0) return 0;
    if(first==2 && c==0) return 0;
    if(dp[first][a][b][c]!=-1) return dp[first][a][b][c];
    dp[first][a][b][c]=0;
    if(first==0)
    {
        dp[first][a][b][c]+=memo(1,a-1,b,c);
        dp[first][a][b][c]+=memo(2,a-1,b,c);
    }
    if(first==1)
    {
        dp[first][a][b][c]+=memo(0,a,b-1,c);
        dp[first][a][b][c]+=memo(2,a,b-1,c);
    }
    if(first==2)
    {
        dp[first][a][b][c]+=memo(0,a,b,c-1);
        dp[first][a][b][c]+=memo(1,a,b,c-1);
    }
    dp[first][a][b][c]%=mod;
    return dp[first][a][b][c];
}

void pre()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<nax;j++)
        {
            for(int k=0;k<nax;k++)
            {
                for(int z=0;z<nax;z++)
                {
                    dp[i][j][k][z]=-1;
                }
            }
        }
    }
    dp[0][1][0][0]=dp[1][0][1][0]=dp[2][0][0][1]=1;
    s[0]=1;
    for(int i=1;i<33;i++)
    {
        s[i]=(long long int)s[i-1]*i;
        s[i]%=mod;
    }
}

int main()
{
    int n,t; cin>>n>>t;
    pre();
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int ile[3];
    memset(ile,0,sizeof ile);
    a[0][0]=1;
    b[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int type,l;
        cin>>l>>type;
        if(type==1)
        {
            for(int i=ile[0];i>=0;i--)
            {
                for(int start=t;start>=0;start--)
                {
                    if(start+l>t) continue;
                    a[i+1][start+l]+=a[i][start];
                    a[i+1][start+l]%=mod;
                }
            }
            ile[0]++;
        }
        else if(type==2)
        {
            for(int i=ile[1];i>=0;i--)
            {
                for(int j=ile[2];j>=0;j--)
                {
                    for(int start=t;start>=0;start--)
                    {
                        if(start+l>t) continue;
                        b[i+1][j][start+l]+=b[i][j][start];
                        b[i+1][j][start+l]%=mod;
                    }
                }
            }
            ile[1]++;
        }
        else if(type==3)
        {
            for(int i=ile[1];i>=0;i--)
            {
                for(int j=ile[2];j>=0;j--)
                {
                    for(int start=t;start>=0;start--)
                    {
                        if(start+l>t) continue;
                        b[i][j+1][start+l]+=b[i][j][start];
                        b[i][j+1][start+l]%=mod;
                    }
                }
            }
            ile[2]++;
        }
    }
    long long int res=0;
    for(int time=0;time<=t;time++)
    {
        for(int i=0;i<=ile[0];i++)
        {
            for(int j=0;j<=ile[1];j++)
            {
                for(int k=0;k<=ile[2];k++)
                {
                    long long int ans=1;
                    ans*=s[i];
                    ans%=mod;
                    ans*=s[j];
                    ans%=mod;
                    ans*=s[k];
                    ans%=mod;
                    long long int suma=0;
                    suma+=memo(0,i,j,k)+memo(1,i,j,k)+memo(2,i,j,k);
                    suma%=mod;
                    ans*=suma;
                    ans%=mod;
                    ans*=a[i][time];
                    ans%=mod;
                    ans*=b[j][k][t-time];
                    ans%=mod;
                    res+=ans;
                    res%=mod;
                }
            }
        }
    }
    cout<<res;
    return 0;
}
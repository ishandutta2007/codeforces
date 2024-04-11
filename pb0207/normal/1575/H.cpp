#include<bits/stdc++.h>
using namespace std;

const int N=511;

int n,m;

char s[N],t[N];

int f[N][N][N],tag[N],tot,fail[N];

int tr[N][2];

void ins(char *s)
{
    int n=strlen(s),x=0;
    for(int i=0;i<n;i++)
    {
        char ch=s[i]-'0';
        if(tr[x][ch]==-1)
        {
            tr[x][ch]=++tot;
            for(int j=0;j<2;j++)
                tr[tot][j]=-1;
        }
        x=tr[x][ch];
    }
    tag[x]=1;
}

queue<int>q;

void getfail()
{
    for(int i=0;i<2;i++)
        if(tr[0][i]!=-1)
            q.push(tr[0][i]),fail[tr[0][i]]=0;
        else
            tr[0][i]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<2;i++)
            if(tr[x][i]!=-1)
                q.push(tr[x][i]),fail[tr[x][i]]=tr[fail[x]][i];
            else
                tr[x][i]=tr[fail[x]][i];
    }
}

int main()
{
    for(int i=0;i<2;i++)
        tr[0][i]=-1;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    scanf("%s",t);
    ins(t);
    getfail();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=tot;j++)
            for(int k=0;k<=n;k++)
                f[i][j][k]=1e9;
    f[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=tot;j++)
            for(int k=0;k<=n-m+1;k++)
                for(int t=0;t<2;t++)
                {
                    int c=s[i+1]!=t+'0';
                    int ni=i+1;
                    int nj=tr[j][t];
                    int nk=k+tag[nj];
                    f[ni][nj][nk]=min(f[ni][nj][nk],f[i][j][k]+c);
                }
    for(int i=0;i<=n-m+1;i++)
    {
        int ans=1e9;
        for(int j=0;j<=tot;j++)
            ans=min(ans,f[n][j][i]);
        printf("%d%c",(ans==1e9?-1:ans)," \n"[i==n-m+1]);
    }
}
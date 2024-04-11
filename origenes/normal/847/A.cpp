#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
queue<int>z,ans;
int main() {
    int i,j,n,m[105][2],t,pout[105];
    memset(m,0,sizeof(m));
    memset(pout,0,sizeof(pout));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&m[i][0],&m[i][1]);
        if(!m[i][0])
            z.push(i);
    }
    while(!z.empty())
    {
        t=z.front();
        z.pop();
        ans.push(t);
        t=m[t][1];
        while(t)
        {
            ans.push(t);
            t=m[t][1];
        }
    }
    i=1;
    while(!ans.empty())
    {
        pout[i++]=ans.front();
        ans.pop();
    }
//    for(i=1;i<=n;i++)
//        printf("%d\n",pout[i]);
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            m[pout[i]][0]=0;
            m[pout[i]][1]=pout[i+1];
        }
        else if(i==n)
        {
            m[pout[i]][0]=pout[i-1];
            m[pout[i]][1]=0;
        }
        else
        {
            m[pout[i]][0]=pout[i-1];
            m[pout[i]][1]=pout[i+1];
        }

    }
    for(i=1;i<=n;i++)
    {
        if(i!=n)
            printf("%d %d\n", m[i][0],m[i][1]);
        else
            printf("%d %d", m[i][0],m[i][1]);
    }
    return 0;
}
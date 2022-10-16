#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    double value[n+1];
    double f[n+1]={};
    vector<vector<int> > graf(n+1);
    for(int i=0;i<n;i++)
    {
        double d;
        scanf("%lf",&d);
        value[i]=1-d;
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    int visited[n]={};
    int parent[n];
    parent[0]=0;
    queue<int> q;
    visited[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int tr=q.front();
        q.pop();
        for(int i=0;i<graf[tr].size();i++)
        {
            int sl=graf[tr][i];
            if(!visited[sl])
            {
                visited[sl]=1;
                q.push(sl);
                parent[sl]=tr;
                f[tr]+=value[sl];
            }
        }
    }
    double resenje=0;
    for(int i=0;i<n;i++)
    {
        resenje+=value[i];
        resenje-=value[i]*f[i];
    }
    int qu;
    scanf("%i",&qu);
    for(int i=0;i<qu;i++)
    {
        int a;
        double x;
        scanf("%i %lf",&a,&x);
        x=1-x;
        resenje-=value[a]-x;
        int p=parent[a];
        if(p!=a)
        {
            resenje+=f[p]*value[p];
            f[p]-=value[a]-x;
            resenje-=f[p]*value[p];
        }
        resenje+=f[a]*value[a];
        value[a]=x;
        resenje-=f[a]*value[a];
        printf("%.6f\n",resenje);
    }
    return 0;
}
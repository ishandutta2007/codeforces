# include <cstdio>
# include <set>
# include <vector>

# define INF 2000000000
# define NMAX 100001

using namespace std;

struct two
{
    int v,w;
    two(int a,int b){v=a;w=b;}
};
vector<two>adjlist[NMAX];

int dj[NMAX];
struct djcomp
{
    bool operator()(const int& i,const int& j)
    {
        return (dj[i]!=dj[j])?(dj[i]<dj[j]):(i<j);
    }
};
set<int,djcomp>djset;

int main()
{
    int N,M,C;
    scanf("%d%d%d",&N,&M,&C);
    
    for(int m=0;m<M;m++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adjlist[a].push_back(two(b,c));
        adjlist[b].push_back(two(a,c));
    }
    
    for(int i=1;i<=N;i++)
        dj[i]=INF;
    dj[C]=0;
    
    for(int i=1;i<=N;i++)
        djset.insert(i);
    
    int dist,ret=0;
    scanf("%d",&dist);
    
    while(!djset.empty())
    {
        int u=*(djset.begin());
        if(dj[u]==dist)ret++;
        djset.erase(djset.begin());
        for(int i=0;i<adjlist[u].size();i++)
        {
            int v=adjlist[u][i].v;
            if(dj[v]>dj[u]+adjlist[u][i].w)
            {
                djset.erase(v);
                dj[v]=dj[u]+adjlist[u][i].w;
                djset.insert(v);
            }
        }
    }
    
    for(int u=1;u<=N;u++)
    {
        for(int i=0;i<adjlist[u].size();i++)
        {
            int v=adjlist[u][i].v;
            if(u>v)continue;
            if(dj[u]<dist&&dj[u]+adjlist[u][i].w>dist)
            {
                int p=dist-dj[u];
                if(dj[v]+adjlist[u][i].w-p>=dist)ret++;
            }
            if(dj[v]<dist&&dj[v]+adjlist[u][i].w>dist)
            {
                int p=dist-dj[u];
                if(dj[v]+adjlist[u][i].w-p>dist)ret++;
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}
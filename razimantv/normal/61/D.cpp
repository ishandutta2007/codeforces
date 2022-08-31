# include <cstdio>
# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

struct two
{
    int vert,weight;
};

vector<two>adjlist [100000];

int maxdepth=0;

void dfs(int vertex,int parent,int depth)
{
    if(depth>maxdepth)maxdepth=depth;
    for(int i=0;i<adjlist[vertex].size();i++)
    {
        int v=adjlist[vertex][i].vert;
        if(v!=parent)dfs(v,vertex,depth+adjlist[vertex][i].weight);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    
    long long ret=0ll;
    for(int i=1;i<N;i++)
    {
        int a;
        two temp;
        scanf("%d%d%d",&a,&temp.vert,&temp.weight);
        --a;--temp.vert;
        adjlist[a].push_back(temp);
        swap(a,temp.vert);
        adjlist[a].push_back(temp);
        ret+=temp.weight;
    }
    ret<<=1;
    
    dfs(0,-1,0);
    cout<<ret-maxdepth<<"\n";
    
    return 0;
}
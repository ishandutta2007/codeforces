#include <cstdio>
#include <vector>
#include <set>
using namespace std;
vector<int> edge[100010];
int giving[100010];
int parent[100010];
bool getting[100010];
vector<int> mylist;

int n;

void in(){
    int m;
    scanf("%d%d",&n,&m);
    for(;m--;){
        int a,b; scanf("%d%d",&a,&b);
        parent[b]=a;
        edge[a].push_back(b);
    }
    for(int i=1; i<=n; ++i) scanf("%d",giving+i), getting[giving[i]]=true;
}

int list_place[100010];

void dfs(int x){
    for(int& y:edge[x]) dfs(y);
    if(getting[x])
        list_place[x]=mylist.size(),
        mylist.push_back(x);
}

bool namnamseo_is_good=true;
set<int> ps;
bool cdvis[100010];
void cd(int x){
    cdvis[x]=true;
    if(getting[x]) ps.insert(list_place[x]);
    if( ps.empty() ||
        ps.find(list_place[giving[x]])==ps.end() ||
        *ps.begin() != list_place[giving[x]]){
        namnamseo_is_good = false;
        return;
    }
    for(int& y:edge[x]) cd(y);
    if(getting[x]) ps.erase(list_place[x]);
}

int main()
{
    in();
    for(int i=1; i<=n; ++i) if(!parent[i]) dfs(i);
    for(int i=1; i<=n; ++i) if(!parent[i]) cd(i);
    if(!namnamseo_is_good){
        puts("-1");
        return 0;
    }
    printf("%u\n",mylist.size());
    for(int& x:mylist) printf("%d ",x);
    return 0;
}
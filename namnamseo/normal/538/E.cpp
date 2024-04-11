#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> edge[200010];
int par [200010];
int hei [200010];

bool leaf[200010];
int leafcnt;

void dfs(int pos){
    if(edge[pos].size()==0) leaf[pos]=true, ++leafcnt;
    else {
        int i,s=edge[pos].size(),nxt;
        for(i=0;i<s;++i){
            nxt=edge[pos][i];
            hei[nxt]=hei[pos]+1;
            par[nxt]=pos;
            dfs(nxt);
        }
    }
}

int chkdfs2(int);

int chkdfs(int pos){
    if(edge[pos].size()==0) return 1;
    else {
        int i,s=edge[pos].size(),nxt, ret=2e8;
        for(i=0;i<s;++i){
            nxt=edge[pos][i];
            ret=min(ret,chkdfs2(nxt));
        }
        return ret;
    }
}

int chkdfs2(int pos){
    if(edge[pos].size()==0) return 1;
    else {
        int i,s=edge[pos].size(),nxt,sum=0;
        for(i=0;i<s;++i){
            nxt=edge[pos][i];
            sum+=chkdfs(nxt);
        }
        return sum;
    }
}



int main()
{
    scanf("%d",&n);
    int i,a,b;
    par[1]=-1;
    for(i=1;i<n;++i) scanf("%d%d",&a,&b), edge[a].push_back(b);
    dfs(1);
    printf("%d %d\n",leafcnt+1-chkdfs(1),chkdfs2(1));
    return 0;
}
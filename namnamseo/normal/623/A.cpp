#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> edge[501];

int groupnum[501];
int groups;

bool conn[501][501];

int visited[501];
int nowtime;

int gr[501];
int gn;

char assigned[502];

int abs(int x){ return x>0?x:-x; }

int main()
{
    scanf("%d%d",&n,&m);
    int i,j,sz,nxt;
    int a,b;
    for(;m--;) scanf("%d%d",&a,&b), edge[a].push_back(b), edge[b].push_back(a), conn[a][b]=1, conn[b][a]=1; 
    for(i=1;i<=n;++i){
        ++nowtime;
        visited[i]=nowtime;
        sz=edge[i].size();
        for(j=0;j<sz;++j){
            nxt=edge[i][j];
            visited[nxt]=nowtime;
        }
        gn=0;
        for(j=1;j<=n;++j){
            if(visited[j]!=nowtime){
                gr[gn++]=j;
            }
        }
        if(gn==0) continue;
        for(j=0;j<gn;++j){
            if(groupnum[gr[j]]) break;
        }
        if(j<gn) {
            for(int k=0;k<gn;++k){
                if(groupnum[gr[k]]!=groupnum[gr[j]]){
                    puts("No"); return 0;
                }
            }
            continue;
        }
        ++groups;
        for(j=0;j<gn;++j){
            a=gr[j];
            groupnum[a]=groups;
            for(int k=j+1;k<gn;++k){
                b=gr[k];
                if((groupnum[a] && groupnum[b] && groupnum[a]!=groupnum[b]) || !conn[a][b]){
                    puts("No");
                    return 0;
                }
            }
        }
    }
    bool flag = 0;
    for(i=1;i<=n;++i){
        if(!groupnum[i]){
            if(!flag) ++groups;
            flag=1;
            groupnum[i]=groups;
        }
    }
    if(groups<=3){
        for(i=1;i<=n;++i) assigned[i]=('a'+(groupnum[i]+1)%3);
        for(i=1;i<=n;++i){
            for(j=i+1;j<=n;++j){
                if((abs(assigned[i]-assigned[j])<=1) != (conn[i][j])){
                    puts("No"); return 0;
                }
            }
        }
        puts("Yes");
        puts(assigned+1);
    } else puts("No");
    return 0;
}
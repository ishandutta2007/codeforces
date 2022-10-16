#include <cstdio>
#include <vector>

using namespace std;

vector <pair <int,int> > g[100005];
int n,m,k,x,y,z,bio[100005];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
    }
    int mi = -1;
    int cur;
    for(int i = 0;i<k;i++){
        scanf("%d",&cur);
        bio[cur] = 1;
    }
    for(int i = 1;i<=n;i++){
        if(bio[i]){
            for(int j = 0;j<g[i].size();j++){
                if((g[i][j].second  < mi || mi == -1) && !bio[g[i][j].first]) mi = g[i][j].second;

            }

        }
    }
    printf("%d\n",mi);
    return 0;
}
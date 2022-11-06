#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;

int deg[65540];
int s  [65540];

int ind[65540];

typedef pair<int,int> pp;
vector<pp> edges;

priority_queue<pp> pq;

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0; i<n; ++i) scanf("%d%d",deg+i,s+i), pq.emplace(-deg[i], i);
    for(; pq.size(); ){
        pp x=pq.top(); pq.pop();
        int me=x.second;
        if(deg[me] != -x.first) continue;
        if(deg[me]==0) continue;
        if(deg[me]==1){
            int you=s[me];
            --deg[you];
            pq.emplace(-deg[you], you);
            s[you]^=me;
            edges.emplace_back(me,you);
        }
    }
    printf("%d\n",(int)edges.size());
    for(pp& t:edges) printf("%d %d\n",t.first, t.second);
    return 0;
}
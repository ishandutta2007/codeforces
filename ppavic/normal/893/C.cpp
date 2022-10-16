#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;

vector < int > v[N];

int bio[N],a[N],n,m;

int ret(int x){
    if(bio[x]) return INF;
    bio[x] = 1;
    int sol = a[x];
    for(int i = 0;i<v[x].size();i++){
        sol = min(ret(v[x][i]) , sol);
    }
    return sol;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
        scanf("%d",a+i);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    long long sm = 0;
    for(int i = 1;i<=n;i++){
        if(bio[i]) continue;
        sm += ret(i);
    }
    printf("%I64d\n",sm);
}
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e6 + 500;

vector < int > v[N], sv, sol;

int n, m, del[N];


int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<m;i++){
        int x, y;scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for(int i = 1;i<=n;i++){
        if(del[i]) continue;
        sv.push_back(i);
        for(int y : v[i])
            del[y] = 1;
    }
    memset(del, 0, sizeof(del));
    for(int i = sv.size() - 1;i >= 0;i --){
        if(del[sv[i]]) continue;
        sol.push_back(sv[i]);
        for(int y : v[sv[i]])
            del[y] = 1;
    }
    printf("%d\n", sol.size());
    for(int x : sol)
        printf("%d ", x);
    printf("\n");
}
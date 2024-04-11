#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 500;

int p[N], n, mks[N], mks2[N], ans[N];

void update(int x){
    if(x == 1) return;
    if(ans[x] > mks2[p[x]]){
        if(ans[x] > mks[p[x]]) mks2[p[x]] = mks[p[x]], mks[p[x]] = ans[x];
        else mks2[p[x]] = ans[x];
    }
    if(p[x] != 1 && ans[p[x]] < max(mks[p[x]], mks2[p[x]] + 1)) ans[p[x]] = max(mks[p[x]], mks2[p[x]] + 1),update(p[x]);
    if(p[x] == 1 && ans[1] < mks[1]) ans[p[x]] = mks[1], update(p[x]);
}

int main(){
    scanf("%d", &n);
    for(int i = 2;i<=n + 1;i++){
        scanf("%d", p + i);
        ans[i] = 1;
        update(i);
        printf("%d ", ans[1]);
    }
    printf("\n");
}
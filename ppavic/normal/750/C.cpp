#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 500;
const int INF = 0x3f3f3f3f;

int n,divv[N],a[N],r[N];

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",&a[i],&divv[i-1]);
        r[i] = r[i-1] + a[i];
    }
    int mks = -INF;
    for(int i = 0;i<=n;i++){
        if(divv[i] == 2) mks = max(mks, r[i]);
    }
    if(mks == -INF){
        printf("Infinity\n");
        return 0;
    }
    int sol = 1899 - mks;
    for(int i = 0;i<n;i++){
        if(sol + r[i] >= 1900 && divv[i] == 2){
            printf("Impossible\n");return 0;
        }
        if(sol + r[i] < 1900 && divv[i] == 1){
            printf("Impossible\n");return 0;
        }
    }
    printf("%d\n",sol + r[n]);
}
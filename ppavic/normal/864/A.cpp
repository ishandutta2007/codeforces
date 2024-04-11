#include <cstdio>

using namespace std;

const int N = 1e5 + 500;

int cnt[N];

int n,dis,a1,a2;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
        if(cnt[x] == 1) dis++;
        if(dis == 1) a1 = x;
        else if(cnt[x] == 1) a2 = x;
        if(dis > 2){
            printf("NO\n"); return 0;
        }
    }
    if(cnt[a1] != cnt[a2]){
        printf("NO\n"); return 0;
    }
    printf("YES\n%d %d\n",a1,a2);
}
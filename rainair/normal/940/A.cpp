#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100 + 5;

int main(){
    int a[MAXN];
    //int dist[MAXN];
    int N,d,ans = 0;
    scanf("%d%d",&N,&d);
    for(int i = 1;i <= N;i++)
        scanf("%d",&a[i]);
    std::sort(a + 1,a + N + 1);
    for(int i = 1;i <= N;i++){
        for(int j = i;j <= N;j++){
            if(a[j] - a[i] > d) continue;
            else ans = std::max(ans,j - i + 1);
        }
    }
    printf("%d\n",N - ans);
    //getchar();getchar();
    return 0;
}
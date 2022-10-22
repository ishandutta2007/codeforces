#include <iostream>

using namespace std;

struct coord{
    int x;
    int y;
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        coord dot[102];
        for(int i=1;i<=n;i++){
            scanf("%d %d", &dot[i].x, &dot[i].y);
        }
        int ans = 10000000;
        for(int i=1;i<=n;i++){
            int m = 0;
            for(int j=1;j<=n;j++){
                m = max(m, abs(dot[i].x-dot[j].x) + abs(dot[i].y-dot[j].y));
            }
            ans = min(ans, m);
        }
        if(ans<=k) printf("1\n");
        else printf("-1\n");
    }
}
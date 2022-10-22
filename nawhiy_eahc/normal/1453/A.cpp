#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int lr[102], du[102];
        for(int i=1;i<=n;i++){
            scanf("%d", &lr[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d", &du[i]);
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(lr[i] == du[j]){
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }
}
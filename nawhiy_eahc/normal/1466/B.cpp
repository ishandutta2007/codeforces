#include <iostream>

using namespace std;

int x[100002];
int cnt[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=1;i<=2*n+1;i++){
            cnt[i] = 0;
        }
        for(int i=1;i<=n;i++){
            scanf("%d", &x[i]);
            cnt[x[i]]++;
        }

        int ans = 0;

        for(int i=1;i<=2*n+1;i++){
            if(cnt[i] > 1) cnt[i+1]++;
            if(cnt[i] > 0) ans++;
        }

        printf("%d\n", ans);
    }
}
#include <iostream>

using namespace std;
int a[200002];
int v[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            a[i] = 0;
            v[i] = 0;
        }
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d", &k);
            a[k]++;
            v[i] = k;
        }
        bool b = true;
        for(int i=1;i<=n;i++){
            if(a[i] == 1){
                int k;
                for(int j=1;j<=n;j++){
                    if(v[j] == i) k = j;
                }
                printf("%d\n", k);
                b = false;
                break;
            }
        }
        if(b) printf("-1\n");
    }
}
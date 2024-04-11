#include <iostream>

using namespace std;
int c[100002];
int temp[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d", &c[i]);
        }
        int result = 1000000;
        for(int i=1;i<=100;i++){
            int cnt = 0;
            for(int j=1;j<=n;j++){
                temp[j] = c[j];
            }
            for(int j=1;j<=n;j++){
                if(temp[j] != i){
                    for(int x = j; x <= j+k-1;x++){
                        temp[x] = i;
                    }
                    cnt++;
                }
            }
            result = min(result, cnt);
        }
        printf("%d\n", result);
    }
}
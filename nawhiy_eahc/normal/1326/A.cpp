#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        if(n == 1) printf("-1\n");
        else if(n%9 == 1){
            for(int i=1;i<=n-2;i++){
                printf("2");
            }
            printf("49\n");
        }
        else{
            for(int i=1;i<=n-1;i++){
                printf("2");
            }
            printf("9\n");
        }
    }
}
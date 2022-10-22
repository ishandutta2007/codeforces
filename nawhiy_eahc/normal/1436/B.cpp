#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((i+j)%n == 0 || (i+j)%n == 1) printf("1 ");
                else printf("0 ");
            }
            printf("\n");
        }
    }
}
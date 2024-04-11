#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        int t = 1;
        for(int i=1;i<=n;i++){
            printf("%c", 'a'+t%3);
            t++;
        }
        printf("\n");
    }
}
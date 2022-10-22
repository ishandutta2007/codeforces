#include <iostream>
#define forn(i, n) for(i=1;i<=n;i++)

using namespace std;
int a[100002];

int main()
{
    int n;
    bool b = true;
    scanf("%d", &n);
    if(n%2==0){
        int sum = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            sum ^=a[i];
        }
        if(sum != 0){
            printf("NO");
            return 0;
        }
        printf("YES\n");
        printf("%d\n", n-2);
        for(int i=1;i<=n-3;i+=2){
            printf("%d %d %d\n", i, i+1, i+2);
        }
        for(int i=1;i<=n-3;i+=2){
            printf("%d %d %d\n", i, i+1, n);
        }
    }
    else{
        printf("YES\n");
        printf("%d\n", n-1);
        for(int i=1;i<=n-2;i+=2){
            printf("%d %d %d\n", i, i+1, i+2);
        }
        for(int i=1;i<=n-2;i+=2){
            printf("%d %d %d\n", i, i+1, n);
        }
    }
}
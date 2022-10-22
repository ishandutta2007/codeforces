#include <iostream>

using namespace std;

int a[52];
int ex[52];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        ex[0] = 0;
        a[0] = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=50;i++){
            ex[i] = 0;
        }

        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ex[a[j]-a[i]] = 1;
            }
        }

        int sum = 0;
        for(int i=0;i<=50;i++){
            sum += ex[i];
        }

        printf("%d\n", sum);
    }
}
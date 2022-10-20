#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int z=0;z<t;z++){
        int n, ans;
        scanf("%d", &n);
        int input[102]={0};
        for (int i=0;i<n;i++){
            scanf("%d", &input[i]);
        }
        if (n%2==0){
            for (int i=0;i<n/2;i++){
                printf("%d %d ", -input[2*i+1], input[2*i]);
            }
            printf("\n");
        }
    }
    return 0;
}
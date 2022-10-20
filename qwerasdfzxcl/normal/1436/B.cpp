#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int z=0;z<t;z++){
        int n;
        scanf("%d", &n);
        if (n%2==0){
            for (int i=0;i<n/2;i++){
                for (int j=0;j<n/2;j++){
                    if (i==j) printf("1 1 ");
                    else printf("0 0 ");
                }
                printf("\n");
                for (int j=0;j<n/2;j++){
                    if (i==j) printf("1 1 ");
                    else printf("0 0 ");
                }
                printf("\n");
            }
        }
        else{
            for (int i=0;i<n/2-1;i++){
                for (int j=0;j<n/2;j++){
                    if (i==j) printf("1 1 ");
                    else if (j==n/2-1) printf("0 0 0");
                    else printf("0 0 ");
                }
                printf("\n");
                for (int j=0;j<n/2;j++){
                    if (i==j) printf("1 1 ");
                    else if (j==n/2-1) printf("0 0 0");
                    else printf("0 0 ");
                }
                printf("\n");
            }
            for (int j=0;j<n/2;j++){
                if (n/2-1==j) printf("1 1 1 ");
                else printf("0 0 ");
            }
            printf("\n");
            for (int j=0;j<n/2;j++){
                if (n/2-1==j) printf("1 1 1 ");
                else printf("0 0 ");
            }
            printf("\n");
            for (int j=0;j<n/2;j++){
                if (n/2-1==j) printf("1 1 1 ");
                else printf("0 0 ");
            }
            printf("\n");
        }
    }
    return 0;
}
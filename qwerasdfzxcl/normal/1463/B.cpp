#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        ll S=0;
        for (int i=0;i<n;i++) S+=a[i];
        ll tmp1=0;
        for (int i=0;i<n;i++){
            if (i%2) tmp1 += a[i]-1;
        }
        if (tmp1<=S/2){
            for (int i=0;i<n;i++){
                if (i%2) printf("1 ");
                else printf("%d ", a[i]);
            }
        }
        else{
            for (int i=0;i<n;i++){
                if ((i+1)%2) printf("1 ");
                else printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
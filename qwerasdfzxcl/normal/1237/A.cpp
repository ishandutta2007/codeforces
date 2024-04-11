#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

int main(){
    int n;
    scanf("%d", &n);
    int c=0;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        if (abs(a[i])%2==1) c++;
    }
    int cur=0;
    for (int i=0;i<n;i++){
        if (abs(a[i])%2==0){
            printf("%d\n", a[i]/2);
        }
        else{
            int val=max((abs(a[i])/2+1)*(a[i]/abs(a[i])), (abs(a[i])/2)*(a[i]/abs(a[i])));
            if (cur<c/2){
                printf("%d\n", val-1);
            }
            else printf("%d\n", val);
            cur++;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        if(a&1){
            printf("First\n");
            return 0;
        }
    }
    printf("Second\n");
    return 0;
}
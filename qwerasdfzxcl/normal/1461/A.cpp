#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100005];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i=0;i<n;i++){
            printf("%c", 97+(i%3));
        }
        printf("\n");
    }
    return 0;
}
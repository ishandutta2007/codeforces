#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    if (n<k*2-1) printf("-1\n");
    else{
        int cnt = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==j && i%2==0 && cnt++<k) printf("R");
                else printf(".");
            }
            printf("\n");
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
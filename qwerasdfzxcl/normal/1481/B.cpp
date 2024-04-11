#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int h[110];

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++) scanf("%d", h+i);
    int val=0;
    while(true){
        bool test=0;
        int pos=-1;
        for (int i=0;i<n-1;i++){
            if (h[i]<h[i+1]){
                pos=i;
                h[i]++;
                test=1;
                break;
            }
        }
        val++;
        if (!test) break;
        if (val==k){
            printf("%d\n", pos+1);
            return;
        }
    }
    printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
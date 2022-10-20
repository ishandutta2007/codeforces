#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int myabs(int x){
    if (x<0) return -x;
    return x;
}

void solve(){
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    if (myabs(x-y)>1) {printf("-1\n"); return;}
    if (x+y>n-2) {printf("-1\n"); return;}

    if (x>=y){
        for (int i=1;i<=n-1-(x+y);i++) printf("%d ", i);
        for (int i=1;i<=x+y+1;i++){
            if (i%2) printf("%d ", n-i/2);
            else if ((x+y+1)%2) printf("%d ", n-(x+y+1)/2-i/2);
            else printf("%d ", n-(x+y)/2-i/2);
        }
    }

    else{
        for (int i=1;i<=n-1-(x+y);i++) printf("%d ", n-i+1);
        for (int i=1;i<=x+y+1;i++){
            if (i%2) printf("%d ", i/2+1);
            else if ((x+y+1)%2) printf("%d ", (x+y+1)/2 + 1 + i/2);
            else printf("%d ", (x+y)/2 + 1 + i/2);
        }
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
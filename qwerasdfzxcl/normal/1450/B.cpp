#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int x[200];
int y[200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0;i<n;i++){
            scanf("%d %d", x+i, y+i);
        }
        bool test0=0;
        for (int i=0;i<n;i++){
            bool test=1;
            for (int j=0;j<n;j++){
                if (i==j) continue;
                if (abs(x[i]-x[j])+abs(y[i]-y[j])>m) test=0;
            }
            if (test){
                test0=1;
                break;
            }
        }
        if (test0) printf("1\n");
        else printf("-1\n");
    }
    return 0;
}
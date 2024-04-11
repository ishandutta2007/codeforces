#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int h[100004];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i=0;i<n;i++) scanf("%d", &h[i]);
        int ans=987654321;
        for (int c=1;c<=100;c++){
            int i=0, tmp=0;
            while(i<n){
                if (h[i]==c) i++;
                else {
                    tmp++;
                    i += k;
                }
            }
            ans=min(tmp, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
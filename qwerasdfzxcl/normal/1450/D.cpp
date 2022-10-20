#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[300005];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", a+i);
        int x=0, y=n-1, z=1;
        int ans1=-1;
        while(x<=y){
            if (min(a[x], a[y])<z) {
                ans1=min(a[x], a[y]);
                break;
            }
            if (a[x]!=z && a[y]!=z){
                bool test1=0;
                for (int i=x;i<=y;i++) {
                    if (a[i]==z) test1=1;
                }
                if (test1) ans1=z;
                else ans1=z-1;
                break;
            }
            else if (a[x]==z && a[y]==z){
                //printf("YES\n");
                ans1=z;
                break;
            }
            else{
                if (a[x]==z){
                    x++;
                    z++;
                }
                else if (a[y]==z){
                    y--;
                    z++;
                }
                else return 1;
            }
        }
        if (ans1==-1) ans1=z-1;
        //printf("%d %d %d %d\n", ans1, z, x, y);
        sort(a, a+n);
        bool test2=1;
        int ans2=987654321;
        for (int i=0;i<n;i++){
            if (a[i]!=i+1) test2=0;
            if (a[i]<i+1) ans2=min(a[i], ans2);
        }
        for (int i=0;i<n;i++){
            if (i>=n-min(ans1, ans2)) printf("1");
            else if (i==0 && test2) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}
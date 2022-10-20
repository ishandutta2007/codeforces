#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100];
int b[100];
int c[100];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i=0;i<n;i++) scanf("%d", &a[i]);
        for (int i=0;i<n;i++) scanf("%d", &b[i]);
        sort(a, a+n);
        sort(b, b+n);
        for (int i=0;i<n;i++) c[i]=b[n-1-i];
        bool test=1;
        for (int i=0;i<n;i++){
            if (a[i]+c[i]>x) {
                test=0;
                break;
            }
        }
        if (test) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
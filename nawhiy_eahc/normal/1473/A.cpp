#include <bits/stdc++.h>

using namespace std;

int a[102];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, d, m = 0;
        scanf("%d %d", &n, &d);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            m = max(m, a[i]);
        }
        sort(a + 1, a+n+1);

        if(m <= d || a[1] + a[2] <= d) printf("yes\n");
        else printf("no\n");
    }
}
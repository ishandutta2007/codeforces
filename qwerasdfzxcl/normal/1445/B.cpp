#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        int a, b, c, d, ans;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ans = max(a+b, c+d);
        printf("%d\n", ans);
    }
    return 0;
}
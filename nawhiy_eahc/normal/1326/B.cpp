#include <iostream>

using namespace std;
typedef long long ll;

ll a[200002];
ll b[200002];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &b[i]);
    }

    ll m = 0;
    a[1] = b[1];
    m = max(m, a[1]);
    for(int i=2;i<=n;i++){
        a[i] = m + b[i];
        m = max(m, a[i]);
    }

    for(int i=1;i<=n;i++){
        printf("%lld ", a[i]);
    }
}
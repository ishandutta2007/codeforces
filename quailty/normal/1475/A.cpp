#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n;
        scanf("%lld",&n);
        printf("%s\n",((n&-n)!=n ? "YES" : "NO"));
    }
    return 0;
}
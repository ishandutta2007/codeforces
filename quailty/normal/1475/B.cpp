#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%s\n",(n%2020<=n/2020 ? "YES" : "NO"));
    }
    return 0;
}
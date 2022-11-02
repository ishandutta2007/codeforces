#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
long long a[MAXN];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        long long cur=1;
        bool ok = true;
        for(int i=1;i<=n;i++)
        {
            if(cur<=1000000000) cur=(cur*(i+1LL))/__gcd(cur,i+1LL);
            if(a[i]%cur==0) ok=false;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}
#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> l,r;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        l.pb(a);
        r.pb(b);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    for(int i=0;i<n;i++)
    {
        res+=max(l[i],r[i]);
    }
    printf("%lld\n",res+n);
    return 0;
}
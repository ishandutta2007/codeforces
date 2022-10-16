#include <bits/stdc++.h>

#define pb push_back
#define ll long long

using namespace std;

ll n,a,t,mx,gde;
vector<ll> el[64];
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
    {
        cin >> a;
        t=a;
        int cnt=0;
        while(a%2==0)
            cnt++,a/=2;
        el[cnt].pb(t);
    }
    for(int i=0;i<64;i++)
        if(el[i].size()>mx)
            mx=el[i].size(),gde=i;
    printf("%i\n",n-mx);
    for(int i=0;i<64;i++)
        if(i!=gde)
            for(auto p:el[i])
                printf("%lld ",p);
    return 0;
}
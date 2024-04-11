#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        ll ans = 0;
        if(x1 == x2)
        {
            ans = abs(y2 - y1);
        }
        else if(y1 == y2)
        {
            ans = abs(x1 - x2);
        }
        else
        {
            ans = abs(x1 - x2) + abs(y1 - y2);
            ans += 2;
        }
        cout<<ans<<"\n";

    }

    return 0;
}
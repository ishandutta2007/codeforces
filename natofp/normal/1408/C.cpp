#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>

using namespace std;

const int nax = 1e5 + 5;
int a[nax];


void solve()
{
    int n,l; cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>a[i];
    long double pos1 = 0;
    long double pos2 = l;

    long double spd1 = 1;
    long double spd2 = 1;

    int gone1 = 0;
    int gone2 = n + 1;
    long double ans = 0;
    while(pos1 != pos2)
    {
        if(gone1 + 1 == gone2)
        {
            long double dis = pos2 - pos1;
            ans += (long double)dis / (spd1 + spd2);
            break;
        }

        long double dst1 = a[gone1 + 1] - pos1;
        long double dst2 = pos2 - a[gone2 - 1];

        long double tm1 = (long double)dst1 / spd1;
        long double tm2 = (long double)dst2 / spd2;


        if(tm1 <= tm2)
        {
            ans += tm1;
            gone1++;
            pos1 += tm1 * spd1;
            pos2 -= tm1 * spd2;
            spd1++;

        }
        else
        {
            ans += tm2;
            gone2--;
            pos1 += tm2 * spd1;
            pos2 -= tm2 * spd2;
            spd2++;

        }



    }
    cout<<setprecision(15)<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}
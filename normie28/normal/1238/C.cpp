#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, n, m, i, j, k, t, x, y, z, res = 0;
ll dp[200011],st[200011];
vector<ll> mons;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (k = 1; k <= t; k++)
    {

        cin >> n >> m;
        for (i=0;i<=m;i++) st[i]=0;
        for (i=1;i<=m;i++) {cin>>x; st[i]=x;}
        res=m-1;
        for (i=2;i<m;i++)
        if (st[i]-st[i+1]==1) {res-=2; i++;}
        if ((st[m]==1)and(i==m)) res--;
            if (res<0) res=0;
        cout<<res<<endl;
    }
}

/*You are playing a game where your character should overcome different obstacles. The current problem is to come down from a cliff. The cliff has height h, and there is a moving platform on each height x from 1 to h.

Each platform is either hidden inside the cliff or moved out. At first, there are n moved out platforms on heights p1,p2,,pn. The platform on height h is moved out (and the character is initially standing there).

If you character is standing on some moved out platform on height x, then he can pull a special lever, which switches the state of two platforms: on height x and x1. In other words, the platform you are currently standing on will hide in the cliff and the platform one unit below will change it state: it will hide if it was moved out or move out if it was hidden. In the second case, you will safely land on it. Note that this is the only way to move from one platform to another.

Your character is quite fragile, so it can safely fall from the height no more than 2. In other words falling from the platform x to platform x2 is okay, but falling from x to x3 (or lower) is certain death.

Sometimes it's not possible to come down from the cliff, but you can always buy (for donate currency) several magic crystals. Each magic crystal can be used to change the state of any single platform (except platform on height h, which is unaffected by the crystals). After being used, the crystal disappears.

What is the minimum number of magic crystal you need to buy to safely land on the 0 ground level?

Input
The first line contains one integer q (1q100)  the number of queries. Each query contains two lines and is independent of all other queries.

The first line of each query contains two integers h and n (1h109, 1nmin(h,2105))  the height of the cliff and the number of moved out platforms.

The second line contains n integers p1,p2,,pn (h=p1>p2>>pn1)  the corresponding moved out platforms in the descending order of their heights.

The sum of n over all queries does not exceed 2105.*/
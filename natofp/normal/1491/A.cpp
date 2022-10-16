#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 1e5 + 5;
int a[nax];
int n,q;

void solve()
{
    int zero = 0;
    int one = 0;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i] == 1) one++;
        else zero++;
    }

    while(q--)
    {
        int tp; cin>>tp;
        if(tp == 1)
        {
            int pos; cin>>pos;
            if(a[pos] == 1)
            {
                one--;
                zero++;
                a[pos] = 0;
            }
            else
            {
                one++;
                zero--;
                a[pos] = 1;
            }
        }
        else
        {
            int k; cin>>k;
            if(one >= k) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}
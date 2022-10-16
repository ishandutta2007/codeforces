#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 5e5 + 5;

char s[nax];

ll dp[nax];

int nxt1[nax];

ll ans = 0;

const int roz = (1<<20);
int tree[roz];
void dodaj(int pos,int val)
{
    pos += roz/2;
    tree[pos] = val;
    pos /= 2;
    while(pos >= 1)
    {
        tree[pos] = max(tree[pos*2],tree[pos*2+1]);
        pos >>= 1;
    }
    return;
}

int ask(int x,int y,int z,int lo,int hi)
{
        hi--;
        lo += roz/2;
        hi += roz/2;
        if(lo > hi) return -1e9;
        int res = tree[lo];
        if(lo != hi) res = max(res,tree[hi]);
        while((lo>>1) != (hi>>1))
        {
            if((lo&1) == 0) res = max(res,tree[lo+1]);
            if(hi&1) res = max(res,tree[hi-1]);
            lo >>= 1;
            hi >>= 1;
        }
        return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    string x; cin>>x;
    for(int i=1;i<=n;i++) s[i] = x[i-1];

    nxt1[n + 1] = n+1;
    for(int i=n;i>=1;i--)
    {
        if(s[i] == '1') nxt1[i] = i;
        else nxt1[i] = nxt1[i+1];
    }

    ll sz = 0;

    for(int i=n;i>=1;i--)
    {
        if(s[i] == '0')
        {
            if(i < n && s[i+1] == '1') dodaj(i + 1,sz);
            int idx = nxt1[i];
            dp[i] = dp[idx];
            sz = 0;
            continue;
        }

        sz++;

        dp[i] += (sz) * (sz + 1) / 2;

        int LO = i + 1;
        int HI = n;
        int pos;
        if(ask(0,roz/2,1,LO,HI+1) <= sz)
        {
            pos = n + 1;
        }
        else
        {
            while(LO + 1 < HI)
            {
                int mid = (LO + HI) / 2;
                if(ask(0,roz/2,1,LO,mid+1) > sz)
                {
                    HI = mid;
                }
                else LO = mid;
            }

            if(ask(0,roz/2,1,LO,LO+1)) pos = LO;
            else pos = HI;
        }


        if(pos == n + 1)
        {
            ll ile = (n - i + 1);
            ile -= sz;
            dp[i] += ile * sz;
            continue;
        }

        ll done = (i + sz - 1);
        dp[i] += (ll)(pos - done - 1) * sz;
        dp[i] += dp[pos];
        dp[i] += (sz * (sz-1) / 2);

    }

    for(int i=1;i<=n;i++) ans += dp[i];
    cout<<ans;



    return 0;
}
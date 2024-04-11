#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>

using namespace std;


vector<pii> ans;

int n;

void go(int lo,int hi)
{
    if(lo == hi) return;
    int mid = (lo + hi) / 2;
    go(lo,mid);
    go(mid+1,hi);
    int len = mid - lo + 1;
    for(int i=lo;i<=mid;i++)
    {
        ans.pb(mp(i,i + len));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    int k = 1;
    while(k * 2 <= n)
    {
        k *= 2;
    }
    go(1,k);
    int rest = n - k;
    if(rest != 0)
    {
        int cur = n;
        int rozjebane = n - k;

        while(rozjebane < k)
        {
            ans.pb(mp(cur,cur - rest));
            cur--;
            rozjebane++;
        }
        go(n-k+1,n);
    }
    cout<<ans.size()<<"\n";
    for(auto akt : ans)
    {
        cout<<akt.st<<" "<<akt.nd<<"\n";
    }




    return 0;
}
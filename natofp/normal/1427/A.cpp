#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 55;
int a[nax];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s = 0;
    for(int i=1;i<=n;i++) s += a[i];
    if(s == 0)
    {
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    vector<int> big,small;
    for(int i=1;i<=n;i++)
    {
        if(a[i] >= 0) big.pb(a[i]);
        else small.pb(a[i]);
    }
    int s1 = 0;
    int s2 = 0;
    for(int x : big) s1 += x;
    for(int x : small) s2 += x;
    s2 = -1 * s2;
    sort(big.begin(),big.end());
    reverse(big.begin(),big.end());
    sort(small.begin(),small.end());
    if(s2 > s1)
    {
        swap(small,big);
    }
    for(int x : big) cout<<x<<" ";
    for(int x : small) cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
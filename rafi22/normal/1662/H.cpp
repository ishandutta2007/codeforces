#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

vector<int>fac(int n)
{
    vector<int>V;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            V.pb(i);
            if(n/i!=i) V.pb(n/i);
        }
    }
    return V;
}
vector<int>Merge(vector<int>a,vector<int>b)
{
    vector<int>ans;
    sort(all(a));
    for(auto x:b) if(binary_search(all(a),x)) ans.pb(x);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int a,b;
        cin>>a>>b;
        vector<int>ans;
        set<int>S;
        vector<int>V=Merge(fac(a),fac(b-2));
        for(auto x:V) S.insert(x);
        V=Merge(fac(a-2),fac(b));
        for(auto x:V) S.insert(x);
        V=Merge(fac(a-1),fac(b-1));
        for(auto x:V) S.insert(x);
        S.insert(2);
        cout<<sz(S)<<" ";
        for(auto x:S) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 200000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c) {string tem(1, c); return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long

/////////////



signed main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
    int t,n,a,b,k;
    cin>>t>>n>>a>>b>>k;
    if(k>n)
    {
        cout<<"0";
        return 0;
    }
    int l=0,r=t;
    while(l<r)
    {
        int m=(l+r+1)/2;
        int tar=m*k;
        int val=min(a,m)*((n+1)/2)+min(b,m)*(n/2);
        if(val>=tar)
        {
            l=m;
        }
        else
        {
            r=m-1;
        }
    }
    cout<<r;
}
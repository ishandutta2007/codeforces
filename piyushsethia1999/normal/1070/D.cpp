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
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long 

//////////////


signed main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    int p=0;
    for(int i=0;i<n;++i)
    {
        if(p==0)
        {
            ans+=a[i]/k;
            p=a[i]%k;
            continue;
        }
        if(a[i]<=k-p)
        {
            ++ans;
            p=0;
        }
        else
        {
            a[i]-=k-p;
            p=0;
            ++ans;
            ans+=a[i]/k;
            p=a[i]%k;
        }
    }
    if(p)
    {
        ++ans;
    }
    cout<<ans;
}
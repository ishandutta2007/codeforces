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
    int n;
    cin>>n;
    vector<int> v11,v10,v01,v00;
    for(int i=0;i<n;++i)
    {
        string s;
        int d;
        cin>>s>>d;
        if(s=="11")
        {
            v11.push_back(d);
        }
        if(s=="10")
        {
            v10.push_back(d);
        }if(s=="01")
        {
            v01.push_back(d);
        }if(s=="00")
        {
            v00.push_back(d);
        }
    }
    sort(v00.begin(),v00.end(),greater<int>());
    sort(v10.begin(),v10.end(),greater<int>());
    sort(v01.begin(),v01.end(),greater<int>());
    sort(v11.begin(),v11.end(),greater<int>());
    int ans=0;
    vector<int>  e;
    if(v10.size()<v01.size())
    {
        int i;
        for(i=0;i<v10.size();++i)
        {
            ans+=v10[i]+v01[i];
        }
        for(;i<v01.size();++i)
        {
            e.push_back(v01[i]);
        }
    }
    else
    {
        int i;
        for(i=0;i<v01.size();++i)
        {
            ans+=v01[i]+v10[i];
        }
        for(;i<v10.size();++i)
        {
            e.push_back(v10[i]);
        }
    }
    for(int i=0;i<v00.size();++i)
    {
        e.push_back(v00[i]);
    }
    sort(e.begin(),e.end(),greater<int>());
    for(int i=0;i<v11.size();++i)
    {
        if(i<e.size())
        {
            ans+=e[i];
        }
        ans+=v11[i];
    }
    cout<<ans;
}
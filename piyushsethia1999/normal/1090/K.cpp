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

/////////////



signed main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
    int n;
    cin>>n;
    map<pair<vector<int>,string>,set<int>> m;
    for(int i=1;i<=n;++i)
    {
        string s,t;
        cin>>s>>t;
        vector<int> f(26,0);
        for(int j=0;j<t.length();++j)
        {
            f[t[j]-'a']=1;
        }
        int j=s.length()-1;
        for(;j>=0;--j)
        {
            if(f[s[j]-'a']==0)
            {
                break;
            }
        }
        m[{f,s.substr(0,j+1)}].insert(i);
    }
    cout<<m.size()<<"\n";
    for(auto r:m)
    {
        cout<<r.S.size()<<" ";
        for(auto g:r.S)
        {
            cout<<g<<" ";
        }
        cout<<"\n";
    }
}
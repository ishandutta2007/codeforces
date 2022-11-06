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
    map<string,int> mi;
    map<string ,string > ms;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        set<string> se;
        for(int j=0;j<s.length();++j)
        {
            for(int k=j;k<s.length();++k)
            {
                se.insert(s.substr(j,k-j+1));
            }
        }
        for(auto r:se)
        {
            mi[r]++;
            ms[r]=s;
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
        string s;
        cin>>s;
        if(mi.find(s)!=mi.end())
        {
            cout<<mi[s]<<" "<<ms[s]<<"\n";
        }
        else
        {
            cout<<"0 - \n";
        }
    }
}
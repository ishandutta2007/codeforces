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
    int n,k;
    cin>>n>>k;
    int a[n],p[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>  v[k+1];
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
        v[a[i]].push_back(p[i]);
    }
    vector<int> ans;
    int c=0;
    int va=0;
    for(int i=1;i<=k;++i)
    {
        if(v[i].size()==0)
        {
            ++c;
        }
        else
        {
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size()-1;++j)
            {
                ans.push_back(v[i][j]);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<c;++i)
    {
        va+=ans[i];
    }
    cout<<va;
}
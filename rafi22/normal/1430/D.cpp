#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int act=1;
        char last=str[0];
        vector <int> v;
        set<int>kolejka;
        for(int i=1;i<n;i++)
        {
            if(str[i]==last) act++;
            else
            {
                v.pb(act);
                last=str[i];
                act=1;
            }
        }
        v.pb(act);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>1)
                kolejka.insert(i);
        }
        int ans=0,p=v.size()-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0) continue;
            ans++;
            kolejka.erase(i);
            if(v[i]==1)
            {
                if(!kolejka.empty())
                {
                    int x=*kolejka.begin();
                    v[x]--;
                    kolejka.erase(x);
                    if(v[x]>1)
                        kolejka.insert(x);
                }
                else v[p--]--;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
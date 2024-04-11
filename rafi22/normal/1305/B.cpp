#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<vector<int>>res;

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
        string s;
        cin>>s;
        int n=sz(s);
        s='#'+s;
        set<int>ans;
        deque<int>stos;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='(') stos.pb(i);
        }
        for(int i=n;i>0;i--)
        {
            if(s[i]==')'&&sz(stos)>0&&stos[0]<i)
            {
                ans.insert(stos[0]);
                ans.insert(i);
                stos.pop_front();
            }
        }
        while(sz(ans)>0)
        {
            vector<int>xd;
            bool b=0;
            int cnt=0;
            for(auto x:ans)
            {
                if(s[x]=='(')
                {
                    if(!b)
                    {
                        xd.pb(x);
                        cnt++;
                    }
                }
                else if(cnt>0)
                {
                    b=1;
                    xd.pb(x);
                    cnt--;
                }
            }
            for(auto x:xd) ans.erase(x);
            res.pb(xd);
        }
        cout<<sz(res)<<endl;
        for(auto x:res)
        {
            cout<<sz(x)<<endl;
            for(auto y:x) cout<<y<<" ";
            cout<<endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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
        vector<int>v(4);
        cin>>v[1]>>v[2]>>v[3];
        cout<<"First"<<endl;
        int k=0;
        while(true)
        {
            vector<pair<int,int>>s;
            s.pb({v[1],1});
            s.pb({v[2],2});
            s.pb({v[3],3});
            sort(s.begin(),s.end());
            int y;
            if(s[2].st-s[1].st==s[1].st-s[0].st&&k==s[2].nd) y=s[2].st-s[1].st;
            else if(k==s[2].nd) y=2*(s[2].st-s[1].st)+(s[1].st-s[0].st);
            else y=s[2].st+7;
            cout<<y<<endl;
            cin>>k;
            if(k==0) break;
            v[k]+=y;
        }
    }

    return 0;
}
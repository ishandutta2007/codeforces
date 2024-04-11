#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
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
        vector<pair<int,int>>p(3);
        set<pair<int,int>>ans;
        cin>>p[0].st>>p[0].nd;
        cin>>p[1].st>>p[1].nd;
        cin>>p[2].st>>p[2].nd;
        sort(all(p));
        int X=p[1].st;
        swap(p[0].st,p[0].nd);
        swap(p[1].st,p[1].nd);
        swap(p[2].st,p[2].nd);
        sort(all(p));
        int Y=p[1].st;
        ans.insert({X,Y});
        for(int i=0;i<3;i++)
        {
            int x=p[i].nd,y=p[i].st;
            while(x!=X||y!=Y)
            {
                ans.insert({x,y});
                if(X>x) x++;
                else if(X<x) x--;
                else if(Y>y) y++;
                else if(Y<y) y--;
            }
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}
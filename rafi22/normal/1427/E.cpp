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

const bool multi=0;

vector <pair<pair<int,int>,bool>> ans;

void multiply(int x,int y)
{
    int act=x,res=0;
    while(y>0)
    {
        if(y&1)
        {
            ans.pb({{res,act},0});
            res+=act;
        }
        ans.pb({{act,act},0});
        act+=act;
        y/=2;
    }
}
pair<int, int> Euklides(int a, int b)
{
    if (b == 0)
        return {1,0};
    pair<int, int> p = Euklides(b, a - (a / b)*b);
    return {p.nd, p.st - (a / b) * p.nd};
}

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
        int x,e,y;
        cin>>x;
        ans.pb({{x,x},1});
        for(int i=30;i>=0;i--)
        {
            if((x&(1<<i))>0)
            {
                e=(1<<i);
                break;
            }
        }
        y=(e*x)^x;
        multiply(x,e);
        ans.pb({{e*x,x},1});
        int a,b;
        pair<int,int> p=Euklides(y,x);
        a=max(abs(p.st),abs(p.nd));
        b=min(abs(p.st),abs(p.nd));
        while(((a*x)^(b*y))!=1)
        {
            a+=y;
            b+=x;
        }
        multiply(x,a);
        multiply(y,b);
        ans.pb({{x*a,y*b},1});
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].nd) cout<<ans[i].st.st<<" ^ "<<ans[i].st.nd<<endl;
            else cout<<ans[i].st.st<<" + "<<ans[i].st.nd<<endl;
        }
    }

    return 0;
}
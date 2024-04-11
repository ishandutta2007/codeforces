#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

const bool multi=1;

bool is[10007];
bool ans[10007];

bool ask(int a,int b,int c)
{
    cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
    bool x;
    cin>>x;
    return x;
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
        memset(ans,0,sizeof ans);
        int n,x,y,X,Y,px,py;
        cin>>n;
        for(int i=0;i<n/3;i++)
        {
            is[i]=ask(i*3,i*3+1,i*3+2);
            if(is[i]) x=i;
            else y=i;
        }
        if(ask(x*3,x*3+1,y*3)&&ask(x*3,x*3+1,y*3+1))
        {
            X=x*3;
            px=x*3+2;
        }
        else if(ask(x*3,x*3+2,y*3)&&ask(x*3,x*3+2,y*3+1))
        {
            X=x*3;
            px=x*3+1;
        }
        else
        {
            X=x*3+1;
            px=x*3;
        }
        if(!ask(y*3,y*3+1,x*3)&&!ask(y*3,y*3+1,x*3+1))
        {
            Y=y*3;
            ans[y*3]=1;
            ans[y*3+1]=1;
            py=y*3+2;
        }
        else if(!ask(y*3,y*3+2,x*3)&&!ask(y*3,y*3+2,x*3+1))
        {
            Y=y*3;
            ans[y*3]=1;
            ans[y*3+2]=1;
            py=y*3+1;
        }
        else
        {
            Y=y*3+1;
            ans[y*3+1]=1;
            ans[y*3+2]=1;
            py=y*3;
        }
        if(!ask(px,X,Y)) ans[px]=1;
        if(!ask(py,X,Y)) ans[py]=1;
        for(int i=0;i<n/3;i++)
        {
            if(i==x||i==y) continue;
            if(is[i])
            {
                if(ask(i*3+1,i*3+2,Y))
                {
                    if(ask(i*3,X,Y))
                    {

                    }
                    else
                    {
                        ans[i*3]=1;
                    }
                }
                else
                {
                    if(ask(i*3+1,X,Y))
                    {
                        ans[i*3+2]=1;
                    }
                    else
                    {
                        ans[i*3+1]=1;
                    }
                }
            }
            else
            {
                if(!ask(i*3+1,i*3+2,X))
                {
                    if(!ask(i*3,X,Y))
                    {
                        ans[i*3]=1;
                        ans[i*3+1]=1;
                        ans[i*3+2]=1;
                    }
                    else
                    {
                        ans[i*3+1]=1;
                        ans[i*3+2]=1;
                    }
                }
                else
                {
                    if(!ask(i*3+1,X,Y))
                    {
                        ans[i*3]=1;
                        ans[i*3+1]=1;
                    }
                    else
                    {
                        ans[i*3]=1;
                        ans[i*3+2]=1;
                    }
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++) if(ans[i]) res.pb(i+1);
        cout<<"! "<<sz(res)<<" ";
        for(auto x:res) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}
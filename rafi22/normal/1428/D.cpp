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

vector<pair<int,int>>ans;
int tab[100007];
bool odw[100007];
deque<int>q;

void gg()
{
    cout<<-1;
    exit(0);
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
        int n,a,last=-1,cnt=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
            if(tab[i]==3)
            {
                if(last==-1) ans.pb({cnt,i});
                else
                {
                    ans.pb({cnt++,i});
                    ans.pb({cnt,i});
                }
                last=i;
            }
        }
        if(last!=-1)
        {
            bool f=0,g=0;
            for(int i=last+1; i<=n; i++)
            {
                if(tab[i]==2)
                {
                    odw[i]=1;
                    ans.pb({cnt++,i});
                    ans.pb({cnt,i});
                    last=i;
                    f=1;
                    break;
                }
            }
            for(int i=last+1; i<=n; i++)
            {
                if(tab[i]==1)
                {
                    odw[i]=1;
                    g=1;
                    if(f) ans.pb({cnt++,i});
                    else
                    {
                        ans.pb({cnt++,i});
                        ans.pb({cnt++,i});
                    }
                    break;
                }
            }
            if(!g) gg();
        }
        for(int i=1;i<=n;i++)
        {
            if(odw[i]) continue;
            if(tab[i]==1)
            {
                if(!q.empty())
                {
                    ans.pb({q[0],i});
                    q.pop_front();
                }
                else
                {
                    ans.pb({cnt++,i});
                }
            }
            else if(tab[i]==2)
            {
                q.pb(cnt);
                ans.pb({cnt++,i});
            }
        }
        if(!q.empty()) gg();
        cout<<ans.size()<<endl;
        for(auto p:ans) cout<<p.st<<" "<<p.nd<<endl;
    }

    return 0;
}
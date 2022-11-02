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

pair<int,int> a[200007];
vector<int> pos[2500007];
vector<pair<int,int>> sum[5000007];
set<int>s;

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
        //KURWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].st;
            a[i].nd=i;
            pos[a[i].st].pb(i);
            s.insert(a[i].st);
        }
        sort(a+1,a+1+n);
        int p1=-1,p2=-1;
        for(int i=1;i<=2500000;i++)
        {
            if(sz(pos[i])>3)
            {
                cout<<"YES"<<endl;
                cout<<pos[i][0]<<" "<<pos[i][1]<<" "<<pos[i][2]<<" "<<pos[i][3]<<endl;
                return 0;
            }
            if(sz(pos[i])>1&&p1==-1) p1=i;
            else if(sz(pos[i])>1&&p2==-1) p2=i;
        }
        if(p1!=-1&&p2!=-1)
        {
            cout<<"YES"<<endl;
            cout<<pos[p1][0]<<" "<<pos[p2][0]<<" "<<pos[p1][1]<<" "<<pos[p2][1]<<endl;
            return 0;
        }
        if(n<=5000)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j].st>a[i].st) sum[a[j].st-a[i].st].pb({a[i].nd,a[j].nd});
                }
            }
            for(int i=1;i<=5000000;i++)
            {
                if(sz(sum[i])>1)
                {
                    for(int j=1;j<sz(sum[i]);j++)
                    {
                        if(sum[i][0].st!=sum[i][j].nd&&sum[i][0].st!=sum[i][j].st&&sum[i][0].nd!=sum[i][j].nd&&sum[i][0].nd!=sum[i][j].st)
                        {
                            //cout<<i<<endl;
                            cout<<"YES"<<endl;
                            cout<<sum[i][0].st<<" "<<sum[i][j].nd<<" "<<sum[i][0].nd<<" "<<sum[i][j].st<<endl;
                            return 0;
                        }
                    }
                }
            }
            cout<<"NO"<<endl;
            return 0;
        }
        //return 2137;
        int it=1;
        while(true)
        {
            int x=-1,y=-1,z=-1,w=-1;
            for(auto i:s)
            {
                if(i-it>0&&sz(pos[i])>0&&sz(pos[i-it])>0)
                {
                    if(x==-1)
                    {
                        x=pos[i-it][0];
                        z=pos[i][0];
                    }
                    else
                    {
                        for(auto q:pos[i-it])
                        {
                            if(q!=z)
                            {
                                y=pos[i][0];
                                w=q;
                                cout<<"YES"<<endl;
                                cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
                                return 0;
                            }
                        }
                    }
                }
                if(i-it>0&&sz(pos[i])>1&&sz(pos[i-it])>1)
                {
                    for(int j=1;j<sz(pos[i-it]);j++)
                    {
                        if(pos[i-it][j]!=z)
                        {
                            y=pos[i][1];
                            w=pos[i-it][j];
                            cout<<"YES"<<endl;
                            cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
                            return 0;
                        }
                    }
                }
            }
            it++;
        }
    }

    return 0;
}
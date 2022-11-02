#include <bits/stdc++.h>

#define int long long
#define double long double
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

int skok[300007][27];
int a[300007],c[300007];
int o[300007];

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
        int q;
        cin>>q>>a[0]>>c[0];
        o[0]=300003;
        for(int i=1;i<=q;i++)
        {
            int t,v,w;
            cin>>t;
            if(t==1)
            {
                cin>>o[i]>>a[i]>>c[i];
                skok[i][0]=o[i];
                for(int j=1;j<=19;j++) skok[i][j]=skok[skok[i][j-1]][j-1];
            }
            else
            {
                cin>>v>>w;
                int a1=0,a2=0;
                while(w>0)
                {
                    int it=19,p=v;
                    while(true)
                    {
                        bool x=0;
                        for(; it>=0; it--)
                        {
                            if(skok[p][it]!=p&&a[skok[p][it]]>0)
                            {
                                x=1;
                                p=skok[p][it];
                                break;
                            }
                        }
                        if(!x) break;
                    }
                    int x=min(w,a[p]);
                    a[p]-=x;
                    w-=x;
                    a1+=x;
                    a2+=x*c[p];
                    if(p==v) break;
                }
                cout<<a1<<" "<<a2<<endl;
            }
        }
    }

    return 0;
}
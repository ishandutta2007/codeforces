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
vector <int> v,v1;
bool is[57];
vector<int> ans[57];


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
       int n,a,od=0;
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>a;
           v.pb(a);
       }
     //  cout<<n<<endl;
       for(int ii=0;ii<n;ii++)
       {
           bool was=0;
           vector <int> x;
            for(int i=1;i<=n;i++) is[i]=0;
            /*for(int i=0;i<n;i++) cout<<v[i]<<" ";
            cout<<endl;*/
            for(int i=v.size()-1;i>=0;i--)
            {
                is[v[i]]=1;
                if(v[i]!=n&&!is[v[i]+1])
                {
                    was=1;
                    int pos,ile=0;
                    for(int j=0;j<n;j++)
                    {
                        if(v[j]==v[i]+1)
                        {
                            pos=j;
                            int jj=j+1;
                            while(jj<n&&v[jj]==v[jj-1]+1)
                            {
                                ile++;
                                jj++;
                            }
                        }
                    }
                    if(pos!=0) x.pb(pos);
                    x.pb(1+ile);
                    x.pb(i-pos-ile);
                    if(i!=v.size()-1) x.pb(v.size()-1-i);
                    break;
                }
            }
            if(!was)
            {
                //x.pb(n);
                od++;
            }
            else
            {
                v1.clear();
                int gr=n-1;
                for(int i=x.size()-1; i>=0; i--)
                {
                    for(int j=gr-x[i]+1; j<=gr; j++) v1.pb(v[j]);
                    gr-=x[i];
                }
                v=v1;
                ans[ii]=x;
            }
       }
       cout<<n-od<<endl;
       for(int i=0;i<n-od;i++)
       {
           cout<<ans[i].size()<<" ";
           for(auto p:ans[i]) cout<<p<<" ";
           cout<<endl;
       }
    }

    return 0;
}
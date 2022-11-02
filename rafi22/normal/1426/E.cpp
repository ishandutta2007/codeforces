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

map<int,int> mapa;
int tab[200007];
int pref[200007];

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
        int n,a1,a2,a3,b1,b2,b3,mn=inf,mx=0;
        cin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
        mx=min(a1,b2)+min(a2,b3)+min(a3,b1);
        vector <int> v;
        for(int i=1;i<=6;i++) v.push_back(i);
        while(true)
        {
            int x1=a1,x2=a2,x3=a3,y1=b1,y2=b2,y3=b3;
            for(int i=0;i<6;i++)
            {
                if(v[i]==1)
                {
                    x1-=min(x1,y1);
                    y1-=min(x1,y1);
                }
                if(v[i]==2)
                {
                    x2-=min(x2,y2);
                    y2-=min(x2,y2);
                }
                if(v[i]==3)
                {
                    x3-=min(x3,y3);
                    y3-=min(x3,y3);
                }
                if(v[i]==4)
                {
                    x2-=min(x2,y1);
                    y1-=min(x2,y1);
                }
                if(v[i]==5)
                {
                    x3-=min(x3,y2);
                    y2-=min(x3,y2);
                }
                if(v[i]==6)
                {
                    x1-=min(x1,y3);
                    y3-=min(x1,y3);
                }
            }
            //cout<<mn<<" "<<x1<<" "<<x2<<" "<<x3<<endl;
            mn=min(mn,x1+x2+x3);
            if(!next_permutation(v.begin(),v.end())) break;
        }
        cout<<mn<<" "<<mx<<endl;

    }

    return 0;
}
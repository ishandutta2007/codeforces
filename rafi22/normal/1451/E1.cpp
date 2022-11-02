#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define ff cout.flush()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int Xor[100007];
int pos[100007];
int ans[100007];

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
        int n,x,o=-1;
        cin>>n;
        pos[0]=1;
        for(int i=2;i<=n;i++)
        {
            cout<<"XOR 1 "<<i<<endl;
            ff;
            cin>>Xor[i];
            if(o==-1&&pos[Xor[i]]!=0)
            {
                cout<<"OR "<<pos[Xor[i]]<<" "<<i<<endl;
                ff;
                cin>>x;
                o=Xor[i]^x;
            }
            pos[Xor[i]]=i;
        }
        if(o==-1)
        {
            cout<<"AND "<<1<<" "<<pos[1]<<endl;
            ff;
            cin>>o;
            cout<<"AND "<<pos[3]<<" "<<pos[1]<<endl;
            ff;
            cin>>x;
            o+=!(x&1);
        }
        for(int i=1;i<=n;i++) ans[i]=Xor[i]^o;
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        ff;
    }

    return 0;
}
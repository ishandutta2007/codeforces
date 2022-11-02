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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a+b==0&&d==c+1)
        {
            cout<<"YES"<<endl;
            cout<<3<<" ";
            for(int i=0;i<c;i++) cout<<2<<" "<<3<<" ";
        }
        else if(a==b+1&&c+d==0)
        {
            cout<<"YES"<<endl;
            cout<<0<<" ";
            for(int i=0;i<b;i++) cout<<1<<" "<<0<<" ";
        }
        else if(b<a||c<d||abs((b-a)-(c-d))>1) cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            if((b-a)-(c-d)==1) cout<<1<<" ";
            for(int i=0;i<a;i++) cout<<0<<" "<<1<<" ";
            for(int i=0;i<min((b-a),(c-d));i++) cout<<2<<" "<<1<<" ";
            for(int i=0;i<d;i++) cout<<2<<" "<<3<<" ";
            if((b-a)-(c-d)==-1) cout<<2<<" ";
        }
    }

    return 0;
}
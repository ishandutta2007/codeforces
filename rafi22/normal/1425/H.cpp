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

const bool multi=1;

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
        if((a+b)%2==1&&(a>0||d>0)) cout<<"Ya"<<" ";
        else cout<<"Tidak"<<" ";
        if((a+b)%2==1&&(b>0||c>0)) cout<<"Ya"<<" ";
        else cout<<"Tidak"<<" ";
        if((a+b)%2==0&&(c>0||b>0)) cout<<"Ya"<<" ";
        else cout<<"Tidak"<<" ";
        if((a+b)%2==0&&(a>0||d>0)) cout<<"Ya"<<" ";
        else cout<<"Tidak"<<" ";
        cout<<endl;
    }

    return 0;
}
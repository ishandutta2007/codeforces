#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int querry(int l,int r)
{
    int x;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>x;
    return x;
}
int tab[1007];
int ans[1007];

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
        int n;
        cin>>n;
        int a=querry(1,2),b=querry(2,3),c=querry(1,3);
        ans[1]=c-b;
        ans[2]=a+b-c;
        ans[3]=c-a;
        for(int i=4;i<=n;i++) ans[i]=querry(i-1,i)-ans[i-1];
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}
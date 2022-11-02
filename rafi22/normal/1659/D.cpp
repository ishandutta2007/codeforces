#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
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

int c[200007];
int a[200007];

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
        int n,s=0,p=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            s+=c[i];
        }
        s/=n;
        priority_queue<int>Q;
        for(int i=n;i>0;i--)
        {
            while(sz(Q)>0&&Q.top()>i) Q.pop();
            int x=i+sz(Q);
            Q.push(p+i+1-s);
            if(c[i]==x)
            {
                a[i]=1;
                p++;
            }
            else a[i]=0;
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}
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

int a[1007][1007];
int ans[1007][1007];

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
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
        vector<int>v0={0,0,0},vx={1,0,0},vy={0,1,0},vz={0,0,1};
        string s;
        cin>>s;
        for(int i=0;i<m;i++)
        {
            if(s[i]=='L') v0[1]--;
            if(s[i]=='R') v0[1]++;
            if(s[i]=='U') v0[0]--;
            if(s[i]=='D') v0[0]++;
            if(s[i]=='I')
            {
                swap(v0[1],v0[2]);
                swap(vx[1],vx[2]);
                swap(vy[1],vy[2]);
                swap(vz[1],vz[2]);
            }
            if(s[i]=='C')
            {
                swap(v0[0],v0[2]);
                swap(vx[0],vx[2]);
                swap(vy[0],vy[2]);
                swap(vz[0],vz[2]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<int>x=v0;
                for(int l=0;l<3;l++)
                {
                    x[l]+=i*vx[l];
                    x[l]+=j*vy[l];
                    x[l]+=(a[i][j]-1)*vz[l];
                    x[l]=(x[l]%n+n)%n;
                }
                ans[x[0]][x[1]]=x[2];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout<<ans[i][j]+1<<" ";
            cout<<endl;
        }
   }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e7+1e3+7,L=2e6;

int n,a[N],nx[N],la[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=L*4;i++)
        nx[i]=-1,la[i]=-1;
    for(int i=2;i<=n;i++)
    {
        a[i]-=a[1];
        nx[a[i]]=a[i],la[a[i]]=a[i];
    }
    nx[0]=la[0]=0;
    for(int i=4*L;i>=0;i--)
        if(nx[i]==-1)
            nx[i]=i==L*4?1e9:nx[i+1];
    for(int i=0;i<=L*4;i++)
        if(la[i]==-1)
            la[i]=!i?1e9:la[i-1];
    int ans=1e13;
    for(int i=1;i<=L;i++)
    {
        if(a[1]>i*i+i+1)
            continue;
        int l=0,r=1e9;
        if(a[1]<i*i)
            l=i*i-a[1];
        r=i*i+i-a[1];
        int s=0,x=i;
        int las=-1;
        while(s<=L*3)
        {
            //[s + i * i, s + x + 1 + i * i]
            int ri=nx[las+1];
            int le=la[s+x];
            // if(le<=L)
            r=min(r,s+x+i*i-(le+a[1]));
            l=max(l,s+i*i-(ri+a[1]));
            las=s+x;
            s+=x*2+1;
            x++;
            // if(ri==a[n]||le==a[n])
            //     break;
        }
        if(r>=l)
            ans=min(ans,l);
    }
    cout<<ans<<endl;
}
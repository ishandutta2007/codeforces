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

const bool multi=1;

int P[200007];
int P1[200007][2];
int a[200007];

int n;

int bs(int i,int d)
{
    int l=3,r=n,sr,xd=2;
    while(l<=r)
    {
        sr=(l+r)/2;
        int j=sr;
        if(j%2==i%2) j++;
        int sp=P[n]-P[i-1]+P1[i-1][i%2]-P1[j][i%2];
        int sc=P[j]+P1[i-1][1-i%2]-P1[j][1-i%2];
        if(j>=i||sp-sc+d<=0) r=sr-1;
        else
        {
            xd=j;
            l=sr+1;
        }
    }
  //  cout<<"aa"<<xd<<endl;
    xd-=2;
    return xd-xd/2;
}

bool check(vector<bool>b)
{
    int s[2]={0,0};
    int last[2]={-1,-1};
    int xd[2]={0,inf};
    for(int i=1;i<=n;i++)
    {
        s[b[i]]+=a[i];
        if(last[b[i]]!=-1)
        {
            if(b[i]==0)
            {
                if(i-last[0]<xd[0]) return 0;
                xd[0]=i-last[0];
            }
            else
            {
                if(i-last[1]>xd[1]) return 0;
                xd[1]=i-last[1];
            }
        }
        last[b[i]]=i;
    }
    if(s[1]>s[0]) return 1;
    return 0;
}

signed main()
{
    //I HATE THIS PROBLEM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod=mod1;
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n<=5)
        {
            for(int i=0;i<(1<<n);i++)
            {
                vector<bool>b(n+1,0);
                for(int j=0;j<n;j++) if((i&(1<<j))) b[j+1]=1;
                ans+=check(b);
            }
            cout<<ans<<endl;
            continue;
        }
        for(int i=2;i<n;i++)
        {
            P[i]=P[i-1]+a[i];
            P1[i][0]=P1[i-1][0]+a[i]*(i%2==0);
            P1[i][1]=P1[i-1][1]+a[i]*(i%2==1);
        }
        P[n]=P[n-1];
        P1[n][0]=P1[n-1][0];
        P1[n][1]=P1[n-1][1];
        //PPPPCCCCC
        for(int i=2;i<n-1;i++) if(P[i]+a[1]>P[n]+a[n]-P[i]) ans++;
        //?CCxxxxxPP?
        for(int i=n-2;i>2;i--)
        {
            ans+=bs(i,a[1]+a[n]);
            ans+=bs(i,a[1]-a[n]);
            ans+=bs(i,a[n]-a[1]);
            ans+=bs(i,-a[1]-a[n]);
        }
        //?CCCCCCCC?
        if(-P[n]+a[1]+a[n]>0) ans++;
        if(-P[n]+a[1]-a[n]>0) ans++;
        if(-P[n]-a[1]+a[n]>0) ans++;
        //?PPPPPPP?
        if(P[n]+a[1]+a[n]>0) ans++;
        if(P[n]+a[1]-a[n]>0) ans++;
        if(P[n]-a[1]+a[n]>0) ans++;
        if(P[n]-a[1]-a[n]>0) ans++;
        //?xxxxxxxPP?
        for(int i=n-2;i>2;i--)
        {
            if(i%2==1&&P[n]-P[i-1]+P1[i-1][i%2]-P1[i-1][1-i%2]+a[1]+a[n]>0) ans++;
            if(i%2==1&&P[n]-P[i-1]+P1[i-1][i%2]-P1[i-1][1-i%2]+a[1]-a[n]>0) ans++;
            if(P[n]-P[i-1]+P1[i-1][i%2]-P1[i-1][1-i%2]-a[1]+a[n]>0) ans++;
            if(P[n]-P[i-1]+P1[i-1][i%2]-P1[i-1][1-i%2]-a[1]-a[n]>0) ans++;
        }
        //?CCxxxxxx?
        for(int i=3;i<n-1;i++)
        {
            if(-P[i]+(P1[n][1-i%2]-P1[i][1-i%2])-(P1[n][i%2]-P1[i][i%2])+a[1]+a[n]>0) ans++;
            if(i%2!=(n-1)%2&&-P[i]+(P1[n][1-i%2]-P1[i][1-i%2])-(P1[n][i%2]-P1[i][i%2])+a[1]-a[n]>0) ans++;
            if(-P[i]+(P1[n][1-i%2]-P1[i][1-i%2])-(P1[n][i%2]-P1[i][i%2])-a[1]+a[n]>0) ans++;
            if(i%2!=(n-1)%2&&-P[i]+(P1[n][1-i%2]-P1[i][1-i%2])-(P1[n][i%2]-P1[i][i%2])-a[1]-a[n]>0) ans++;
        }
        //?xxxxxxx?
        vector<bool>b(n+1,0);
        for(int i=2;i<n;i+=2) b[i]=1;
        b[1]=1,b[n]=1;
        ans+=check(b);
        b[1]=1,b[n]=0;
        ans+=check(b);
        b[1]=0,b[n]=1;
        ans+=check(b);
        b[1]=0,b[n]=0;
        ans+=check(b);
        b=vector<bool>(n+1,1);
        for(int i=2;i<n;i+=2) b[i]=0;
        b[1]=1,b[n]=1;
        ans+=check(b);
        b[1]=1,b[n]=0;
        ans+=check(b);
        b[1]=0,b[n]=1;
        ans+=check(b);
        b[1]=0,b[n]=0;
        ans+=check(b);
        cout<<ans%mod<<endl;
    }

    return 0;
}
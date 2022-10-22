#include<bits/stdc++.h>
using namespace std;

#define int long long

const int P=1e9+7;

const int N=1e6+1e3+7;

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int f[N],g[N],s[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    g[0]=(P+1)/2;
    for(int i=1;i<=(int)1e6;i++)
        g[i]=(g[i-1]+qpow(qpow(2,i+1),P-2))%P;
    while(T--)
    {
        int n;
        cin>>n;
        int last=n-1;
        f[n]=1;
        int s=0;
        for(int i=n-1;i>=1;i--)
        {
            f[i]=0;
            s=s*qpow(2,P-2)%P;
            int nr=i+min(n-i-1,i-1);
            while(last>nr)
                s=(s-f[last]*qpow(qpow(2,last-i),P-2)%P+P)%P,last--;
            f[i]=s;
            if(n-i<i)
                f[i]=(f[i]+f[n]*qpow(qpow(2,n-i-1)%P,P-2)%P)%P;
            s=(s+f[i])%P;
            // int nr=4
            // f[i]=f[i]
            //[1, min(i , n - i)]
            // for(int j=1;j+i<=n&&j<i;j++)
            //     f[i]=(f[i]+f[i+j]*qpow(qpow(2,j-(j+i==n)),P-2)%P)%P;
        }
        for(int i=1;i<=n;i++)
        {
            int ans=0;
            // vector<int>f(n*2);
            // f[i]=1;
            // for(int j=i;j<n;j++)
            // {
            //     for(int k=1;k<j;k++)
            //         (f[j+k]+=f[j]*qpow(qpow(2,k),P-2))%=P;
            // }
            // cout<<i<<" "<<f[n]*qpow(2,n-1)%P - last<<endl;
            // last = f[n] * qpow(2, n-1)%P;
            // f[n] = f[n] * 2 % P;
            // if(i!=n)
            //     f[n]=f[n]*2%P;
            // int coe=f[n-i]*(i!=n?2:1)%P;
            int coe=f[i];
            if(i!=n)
            {
                // for(int j=(i+1)/2;j<=i;j++)
                //     ans=(ans+qpow(qpow(2,j-(i==j)+1),P-2)*coe%P)%P;
                // int cff=0;
                // for(int j=(i+1)/2;j<i;j++)
                //     cff=(cff+qpow(qpow(2,j+1),P-2)%P);
                // cff=(cff+qpow(qpow(2,i),P-2))%P;
                int cff=(g[i-1]-g[(i+1)/2-1]+P+qpow(qpow(2,i),P-2)%P)%P;
                ans=(ans+cff*coe)%P;
            }
            else
            {
                // for(int j=(i+1)/2;j<=i;j++)
                //     ans=(ans+qpow(qpow(2,j-1-(i==j)+1),P-2)*coe%P)%P;
                
                int cff=((i-2>=0?g[i-2]:0)-((i+1)/2-2>=0?g[(i+1)/2-2]:0)+P+qpow(qpow(2,i-1),P-2)%P)%P;
                ans=(ans+cff*coe)%P;
            }
            cout<<ans%P<<"\n";
        }
    }
}
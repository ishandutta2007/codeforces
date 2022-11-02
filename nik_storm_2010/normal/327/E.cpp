#include<iostream>

using namespace std;
const int module=1000000007,N=24;

long long a[N+1],b[N+1],f[1<<N];
int n,m;

int main() {
    b[1]=0; b[2]=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
    f[0]=0;
    for (int i=1;i<=(1<<n);i++)
            for (int j=0;j<n;j++)
                if ((i&(1<<j))!=0) {
                    f[i]=f[i^(1<<j)]+a[j+1];
                    break;
                }
    for (int i=1;i<=(1<<n);i++)
        if ((f[i]==b[1])||(f[i]==b[2])) f[i]=-1;
    f[0]=1;
    for (int i=1;i<=(1<<n);i++)
        if (f[i]==-1) f[i]=0;
        else {
            f[i]=0;
            for (int j=0;j<n;j++) if ((i&(1<<j))!=0) f[i]+=f[i^(1<<j)];
            f[i]%=module;
        }
    cout<<f[(1<<n)-1];
    return 0;
}
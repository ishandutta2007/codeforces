#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef long long ll;
ll n,c,now;
ll f[2][10005],p[10005],s[10005];

int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        cin>>s[i];
    memset(f[now],0x3f,sizeof(f[now]));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
    	now^=1;
    	memset(f[now],0x3f,sizeof(f[now]));
    	f[now][0]=f[now^1][0]+p[i];
        for(int j=1;j<i;j++)
            f[now][j]=min(f[now^1][j-1]+s[i],f[now^1][j]+p[i]+c*j);
        f[now][i]=f[now^1][i-1]+s[i];
    }
    ll ans=0x3f3f3f3f3f3f3f;
    for(int i=0;i<=n;i++)
        ans=min(ans,f[now][i]);
    cout<<ans<<endl;
    return 0;
}
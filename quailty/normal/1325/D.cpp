#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll u,v;
    scanf("%lld%lld",&u,&v);
    if(u>v || (u-v)%2!=0)return 0*printf("-1\n");
    vector<ll> res(3);
    int mx=0;
    ll d=(v-u)/2;
    for(int i=0;i<60;i++)
    {
        int st=(d>>i&1)*2+(u>>i&1);
        for(int j=0;j<st;j++)
            res[j]|=(1LL<<i);
        mx=max(mx,st);
    }
    printf("%d\n",mx);
    for(int j=0;j<mx;j++)
        printf("%lld%c",res[j]," \n"[j==mx-1]);
    return 0;
}
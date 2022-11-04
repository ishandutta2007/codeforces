#include<bits/stdc++.h>
using namespace std;
const int Mod=1000000007;
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int p[75];
int main()
{
    int cnt=0;
    for(int i=2;i<=70;i++)
        if(isprime(i))p[cnt++]=i;
    vector<int> base;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,t=0;
        scanf("%d",&a);
        for(int i=0;i<cnt;i++)if(a%p[i]==0)
            while(a%p[i]==0)a/=p[i],t^=(1<<i);
        for(int i=0;i<(int)base.size();i++)
            t=min(t,t^base[i]);
        if(t)base.push_back(t);
    }
//    printf("%d\n",(int)base.size());
    int res=1;
    for(int i=(int)base.size();i<n;i++)
        res=2*res%Mod;
    printf("%d\n",(res+Mod-1)%Mod);
    return 0;
}
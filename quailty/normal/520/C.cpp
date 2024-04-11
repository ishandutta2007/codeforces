#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
char s[100005];
int cnt[7];
ll mpow(int k,int n)
{
    ll res=1;
    for(int i=1;i<=n;i++)
    {
        res=(res*k)%Mod;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')cnt[0]++;
        if(s[i]=='C')cnt[1]++;
        if(s[i]=='G')cnt[2]++;
        if(s[i]=='T')cnt[3]++;
    }
    sort(cnt,cnt+4);
    if(cnt[0]==cnt[3])printf("%I64d",mpow(4,n));
    else if(cnt[1]==cnt[3])printf("%I64d",mpow(3,n));
    else if(cnt[2]==cnt[3])printf("%I64d",mpow(2,n));
    else printf("1");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;char s[110];
        scanf("%d%d%s",&n,&k,s+1);
        int pos=k+1;
        rep(i,k)if(s[i]!=s[n-i+1]){pos=i;break;}
        puts(pos>=k+1&&2*k<n?"YES":"NO");
    }
    return 0;
}
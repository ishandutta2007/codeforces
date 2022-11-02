#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
string s[22],t[22];
int n,m,q;
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,n)cin>>s[i];
    rep(i,m)cin>>t[i];
    scanf("%d",&q);
    rep(i,q)
    {
        int x;scanf("%d",&x);
        cout<<s[(x-1)%n+1]<<t[(x-1)%m+1]<<"\n";
    }
    return 0;
}
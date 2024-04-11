#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
void solve()
{
    int n;
    scanf("%d",&n);
    map<string,int> mp;
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        char buf[5];
        scanf("%s",buf);
        string str=buf;
        for(int i=0;i<2;i++)
        {
            string tmp=str;
            for(int j='a';j<='k';j++)
            {
                tmp[i]=j;
                if(mp.count(tmp))res+=mp[tmp];
            }
        }
        res-=2*mp[str];
        mp[str]++;
    }
    printf("%lld\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
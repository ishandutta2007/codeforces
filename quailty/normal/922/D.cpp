#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
char buff[MAXN];
string str[MAXN];
int id[MAXN],cnt[MAXN][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buff);
        str[i]=buff,id[i]=i;
        for(int j=0;j<(int)str[i].size();j++)
        {
            cnt[i][0]+=(str[i][j]=='s');
            cnt[i][1]+=(str[i][j]=='h');
        }
    }
    sort(id+1,id+n+1,[](int x,int y){return 1LL*cnt[x][0]*cnt[y][1]>1LL*cnt[x][1]*cnt[y][0];});
    ll res=0,now=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)str[id[i]].size();j++)
        {
            if(str[id[i]][j]=='s')now++;
            else res+=now;
        }
    return 0*printf("%lld\n",res);
}
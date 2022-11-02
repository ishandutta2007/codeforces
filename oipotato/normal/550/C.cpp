#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
struct data
{
    int pos,del,mo;
};
queue<data>q;
int predel[110][110][8],premo[110][110][8];
bool vis[110][110][8];
char s[110];
int n;
void print(int pos,int del,int mo)
{
    puts("YES");
    vector<char>ans;
    for(int i=pos;i;i--)
    {
        if(predel[i][del][mo]==del)ans.pb(s[i]);
        int ndel=predel[i][del][mo],nmo=premo[i][del][mo];
        del=ndel;mo=nmo;
    }
    reverse(ans.begin(),ans.end());
    for(auto c:ans)putchar(c);
    puts("");
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    q.push({0,0,0});
    for(;!q.empty();q.pop())
    {
        auto u=q.front();
        int pos=u.pos,del=u.del,mo=u.mo;
        if(del<pos&&!mo){print(pos,del,mo);return 0;;}
        if(pos==n)continue;
        pos++;mo=(mo*10+s[pos]-'0')%8;
        if(!vis[pos][del][mo])q.push({pos,del,mo}),vis[pos][del][mo]=1,predel[pos][del][mo]=u.del,premo[pos][del][mo]=u.mo;
        del++;mo=u.mo;
        if(!vis[pos][del][mo])q.push({pos,del,mo}),vis[pos][del][mo]=1,predel[pos][del][mo]=u.del,premo[pos][del][mo]=u.mo;
    }
    puts("NO");
    return 0;
}
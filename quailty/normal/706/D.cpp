#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
struct node
{
    int nxt[2],cnt;
    void newnode()
    {
        memset(nxt,0,sizeof(nxt));
        cnt=0;
    }
}s[MAXN*32];
int tot,root;
void update(int x,int v)
{
    int p=root;
    for(int i=29;i>=0;i--)
    {
        int id=x>>i&1;
        if(!s[p].nxt[id])
        {
            s[++tot].newnode();
            s[p].nxt[id]=tot;
        }
        p=s[p].nxt[id];
        s[p].cnt+=v;
    }
}
int query(int x)
{
    int res=0,p=root;
    for(int i=29;i>=0;i--)
    {
        int id=x>>i&1;
        if(!s[p].nxt[id^1] || !s[s[p].nxt[id^1]].cnt)p=s[p].nxt[id];
        else
        {
            p=s[p].nxt[id^1];
            res|=1<<i;
        }
    }
    return res;
}
int main()
{
    int q;
    scanf("%d",&q);
    s[root=++tot].newnode();
    update(0,1);
    while(q--)
    {
        char ty[5];
        int x;
        scanf("%s%d",ty,&x);
        if(*ty!='?')update(x,(*ty=='+' ? 1 : -1));
        else printf("%d\n",query(x));
    }
    return 0;
}
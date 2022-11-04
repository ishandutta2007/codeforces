#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=300005;
const int SIZE=605;
string str[MAXN];
int val[MAXN];
vector<int>sma,big;
struct AhoCorasick
{
    int nxt[MAXN][26],fail[MAXN],ed[MAXN];
    int root,L;
    int newnode()
    {
        for(int i=(ed[L]=0);i<26;i++)
            nxt[L][i]=-1;
        return L++;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void add(string &buf,int val)
    {
        int now=root;
        for(int i=0;i<(int)buf.size();i++)
        {
            if(nxt[now][buf[i]-'a']==-1)
                nxt[now][buf[i]-'a']=newnode();
            now=nxt[now][buf[i]-'a'];
        }
        ed[now]+=val;
    }
    void build()
    {
        queue<int>q;
        fail[root]=root;
        for(int i=0;i<26;i++)
        {
            if(nxt[root][i]==-1)
                nxt[root][i]=root;
            else
            {
                fail[nxt[root][i]]=root;
                q.push(nxt[root][i]);
            }
        }
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=0;i<26;i++)
            {
                if(nxt[now][i]==-1)
                    nxt[now][i]=nxt[fail[now]][i];
                else
                {
                    fail[nxt[now][i]]=nxt[fail[now]][i];
                    ed[nxt[now][i]]+=ed[fail[nxt[now][i]]];
                    q.push(nxt[now][i]);
                }
            }
        }
    }
    int query(string &buf)
    {
        int now=root,res=0;
        for(int i=0;i<(int)buf.size();i++)
        {
            now=nxt[now][buf[i]-'a'];
            res+=ed[now];
        }
        return res;
    }
}AC_sma,AC_big;
char buf[MAXN];
int main()
{
    int m,tot=0;
    scanf("%d",&m);
    while(m--)
    {
        int t;
        scanf("%d%s",&t,buf);
        string tmp=buf;
        if(t<=2)
        {
            str[++tot]=tmp;
            val[tot]=3-2*t;
            sma.push_back(tot);
            AC_sma.init();
            for(int i=0;i<(int)sma.size();i++)
                AC_sma.add(str[sma[i]],val[sma[i]]);
            if(AC_sma.L>SIZE)
            {
                AC_sma.init();
                for(int i=0;i<(int)sma.size();i++)
                    big.push_back(sma[i]);
                sma.clear();
                AC_big.init();
                for(int i=0;i<(int)big.size();i++)
                    AC_big.add(str[big[i]],val[big[i]]);
                AC_big.build();
            }
            AC_sma.build();
        }
        else
        {
            printf("%d\n",AC_sma.query(tmp)+AC_big.query(tmp));
            fflush(stdout);
        }
    }
    return 0;
}
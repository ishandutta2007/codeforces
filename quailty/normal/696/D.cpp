#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
struct Matrix
{
    ll a[205][205];
    Matrix()
    {
        for(int i=0;i<=200;i++)
            for(int j=0;j<=200;j++)
                a[i][j]=-INF;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<=200;i++)
            for(int k=0;k<=200;k++)
                for(int j=0;j<=200;j++)
                    C.a[i][j]=max(C.a[i][j],a[i][k]+B.a[k][j]);
        return C;
    }
    Matrix operator ^ (const ll &t)const
    {
        Matrix A=(*this),res=A;
        ll p=t-1;
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
struct node
{
    static int tot;
    int nxt[26],fail,val;
    void newnode()
    {
        memset(nxt,-1,sizeof(nxt));
        fail=-1;
        val=0;
    }
}s[205];
int root=0,node::tot=0,c[205];
void add(char str[],int val)
{
    int p=root;
    for(int i=0;str[i];i++)
    {
        int idx=str[i]-'a';
        if(s[p].nxt[idx]==-1)
        {
            s[++node::tot].newnode();
            s[p].nxt[idx]=node::tot;
        }
        p=s[p].nxt[idx];
    }
    s[p].val+=val;
}
void getFail()
{
    queue<int>q;
    s[root].fail=root;
    q.push(root);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(s[u].nxt[i]==-1)continue;
            int v=s[u].nxt[i];
            if(u==root)s[v].fail=root;
            else
            {
                int p=s[u].fail;
                while(p!=root && s[p].nxt[i]==-1)p=s[p].fail;
                s[v].fail=(s[p].nxt[i]==-1 ? root : s[p].nxt[i]);
            }
            s[v].val+=s[s[v].fail].val;
            q.push(v);
        }
    }
}
Matrix build()
{
    Matrix t;
    for(int i=0;i<=node::tot;i++)
        for(int j=0;j<26;j++)
        {
            int p=i;
            while(p!=root && s[p].nxt[j]==-1)p=s[p].fail;
            p=(s[p].nxt[j]==-1 ? root : s[p].nxt[j]);
            t.a[i][p]=s[p].val;
        }
    return t;
}
char str[205];
int main()
{
    int n;
    ll L;
    scanf("%d%I64d",&n,&L);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    s[root].newnode();
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        add(str,c[i]);
    }
    getFail();
    Matrix A=build()^L;
    ll res=0;
    for(int i=0;i<=node::tot;i++)
        res=max(res,A.a[0][i]);
    return 0*printf("%I64d",res);
}
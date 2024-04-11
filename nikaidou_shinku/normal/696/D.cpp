#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
struct Matrix
{
    ll a[205][205];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<200;i++)a[i][i]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        memset(C.a,-1,sizeof(C.a));
        for(int i=0;i<205;i++)
            for(int k=0;k<205;k++)
                for(int j=0;j<205;j++)
                    if(a[i][k]>=0 && B.a[k][j]>=0)
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
    int nxt[26],fail,val;
    void newnode()
    {
        memset(nxt,-1,sizeof(nxt));
        fail=-1;
        val=0;
    }
}t[205];
int root=0,tot=0;
void insert(string &str,int val)
{
    int p=root;
    for(int i=0;i<(int)str.size();i++)
    {
        int idx=str[i]-'a';
        if(t[p].nxt[idx]==-1)
        {
            t[++tot].newnode();
            t[p].nxt[idx]=tot;
        }
        p=t[p].nxt[idx];
    }
    t[p].val+=val;
}
void build_ac()
{
    queue<int>q;
    t[root].fail=root;
    for(int i=0;i<26;i++)
    {
        if(t[root].nxt[i]==-1)
            t[root].nxt[i]=root;
        else
        {
            t[t[root].nxt[i]].fail=root;
            q.push(t[root].nxt[i]);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        t[u].val+=t[t[u].fail].val;
        for(int i=0;i<26;i++)
        {
            if(t[u].nxt[i]==-1)
                t[u].nxt[i]=t[t[u].fail].nxt[i];
            else
            {
                t[t[u].nxt[i]].fail=t[t[u].fail].nxt[i];
                q.push(t[u].nxt[i]);
            }
        }
    }
}
void build(Matrix &M)
{
    memset(M.a,-1,sizeof(M.a));
    for(int i=0;i<=tot;i++)
        for(int j=0;j<26;j++)
            M.a[i][t[i].nxt[j]]=t[t[i].nxt[j]].val;
}
int c[205];
int main()
{
    ios::sync_with_stdio(false);
    ll n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>c[i];
    t[root].newnode();
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        insert(t,c[i]);
    }
    build_ac();
    Matrix M;
    build(M);
    M=M^l;
    ll res=0;
    for(int i=0;i<=tot;i++)
        res=max(res,M.a[0][i]);
    cout<<res<<endl;
    return 0;
}
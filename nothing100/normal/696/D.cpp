#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define mo 1000000007
using namespace std;
struct matrix
{
    long long a[210][210];
}ans,zy;
string s;
int n,bo,a[210],num,tree[210][26],next[210],val[210];
long long l,an;
void clean(matrix &x)
{
    for (int i=0;i<=num;i++)
    for (int j=0;j<=num;j++) x.a[i][j]=-mo;
    return;
}
matrix operator +(matrix x,matrix y)
{
    matrix c;
    clean(c);
    for (int k=0;k<=num;k++)
    for (int i=0;i<=num;i++)
    for (int j=0;j<=num;j++) c.a[i][j]=max(c.a[i][j],x.a[i][k]+y.a[k][j]);
    return c;
}
void build()
{
    int que[200],head=-1,tail=-1;
    for (int i=0;i<26;i++)
    if (tree[0][i])
    {
        que[++tail]=tree[0][i];
        zy.a[0][tree[0][i]]=val[tree[0][i]];
    }
    while (head!=tail)
    {
        head++;
        for (int i=0;i<26;i++)
        {
            int tmp=next[que[head]];
            while ((tmp)&&(!tree[tmp][i])) tmp=next[tmp];
            if (tree[tmp][i]) tmp=tree[tmp][i];
            if (tree[que[head]][i])
            {
                que[++tail]=tree[que[head]][i];
                next[tree[que[head]][i]]=tmp;
                val[tree[que[head]][i]]=val[tree[que[head]][i]]+val[tmp];
                zy.a[que[head]][tree[que[head]][i]]=val[tree[que[head]][i]];
            }
            else zy.a[que[head]][tmp]=val[tmp];
        }
    }
    return;
}
int main()
{
    scanf("%d%I64d",&n,&l);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
    {
        cin>>s;
        int l=s.length(),tmp=0;
        for (int j=0;j<l;j++)
        {
            if (tree[tmp][s[j]-'a']==0) tree[tmp][s[j]-'a']=++num;
            tmp=tree[tmp][s[j]-'a'];
        }
        val[tmp]=val[tmp]+a[i];
    }
    clean(zy);
    clean(ans);
    ans.a[0][0]=0;
    for (int i=0;i<=num;i++) zy.a[i][i]=0;
    build();
    while (l)
    {
        if (l&1) ans=ans+zy;
        zy=zy+zy;
        l=l/2;
    }
    for (int i=0;i<=num;i++) an=max(an,ans.a[0][i]);
    printf("%I64d",an);
    return 0;
}
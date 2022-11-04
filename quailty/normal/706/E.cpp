#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=1005;
struct node
{
    int v;
    node *right,*down;
}s[MAXN][MAXM];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&s[i][j].v);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            s[i][j].right=&s[i][j+1];
            s[i][j].down=&s[i+1][j];
        }
    while(q--)
    {
        int a,b,c,d,h,w;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
        node *nowu[2]={&s[a-1][0],&s[c-1][0]};
        node *nowd[2]={&s[a+h-1][0],&s[c+h-1][0]};
        for(int i=1;i<=b;i++)
        {
            nowu[0]=nowu[0]->right;
            nowd[0]=nowd[0]->right;
        }
        for(int i=1;i<=d;i++)
        {
            nowu[1]=nowu[1]->right;
            nowd[1]=nowd[1]->right;
        }
        node *nowl[2]={&s[0][b-1],&s[0][d-1]};
        node *nowr[2]={&s[0][b+w-1],&s[0][d+w-1]};
        for(int i=1;i<=a;i++)
        {
            nowl[0]=nowl[0]->down;
            nowr[0]=nowr[0]->down;
        }
        for(int i=1;i<=c;i++)
        {
            nowl[1]=nowl[1]->down;
            nowr[1]=nowr[1]->down;
        }
        for(int i=1;i<=w;i++)
        {
            swap(nowu[0]->down,nowu[1]->down);
            nowu[0]=nowu[0]->right;
            nowu[1]=nowu[1]->right;
            swap(nowd[0]->down,nowd[1]->down);
            nowd[0]=nowd[0]->right;
            nowd[1]=nowd[1]->right;
        }
        for(int i=1;i<=h;i++)
        {
            swap(nowl[0]->right,nowl[1]->right);
            nowl[0]=nowl[0]->down;
            nowl[1]=nowl[1]->down;
            swap(nowr[0]->right,nowr[1]->right);
            nowr[0]=nowr[0]->down;
            nowr[1]=nowr[1]->down;
        }
    }
    for(int i=1;i<=n;i++,printf("\n"))
    {
        node *now=&s[i][0];
        for(int j=1;j<=m;j++)
        {
            now=now->right;
            printf("%d ",now->v);
        }
    }
    return 0;
}
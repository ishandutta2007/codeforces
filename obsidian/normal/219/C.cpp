#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int oo=1000000000;
int dp[500100][26],pr[50010][26];
char s[500100];
struct Node{int va,id;}q[40];
bool cmp(Node x,Node y)
{return x.va<y.va;}
int n,K;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        scanf("%s",s);
        for(int i=0;i<K;i++)
        dp[0][i]=1;
        dp[0][s[0]-'A']=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<K;j++)dp[i][j]=oo;
            for(int j=0;j<K;j++)
            {q[j].va=dp[i-1][j];q[j].id=j;}
            sort(q,q+K,cmp);
            for(int j=0;j<K;j++)
            {
                int cost=0;
                if(s[i]-'A'!=j)cost=1;
                if(q[0].id==j)dp[i][j]=cost+q[1].va,pr[i][j]=q[1].id;
                else dp[i][j]=cost+q[0].va,pr[i][j]=q[0].id;
            }
        }
        int ret=oo,now=-1;
        for(int i=0;i<K;i++)
        {
            if(dp[n-1][i]<ret)
            ret=dp[n-1][i],now=i;
        }
        printf("%d\n",ret);
        for(int i=n-1;i>=0;i--)
        {
            s[i]=now+'A';
            now=pr[i][now];
        }
        puts(s);
    }
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
int a[MAXN<<1],top;
pair<int,int> stk[MAXN];
int mx[2][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i<2*n;i++)
        a[i]=a[i-n];
    int st=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[st])st=i,cnt=0;
        if(a[i]==a[st])cnt++;
    }
    long long res=0;
    for(int i=st,j=0;j<n;i++,j++)
    {
        bool flag=0;
        while(top>0 && a[i]>=stk[top].first)
        {
            res+=stk[top--].second;
            flag=1;
        }
        if(top)res+=1;
        if(flag && stk[top+1].first==a[i])stk[++top].second++;
        else stk[++top]=make_pair(a[i],1);
    }
    while(top>0 && a[st]>stk[top].first)res+=stk[top--].second;
    if(cnt==1)
    {
        for(int i=st+1,j=1;j<n;i++,j++)
            mx[0][j]=max(mx[0][j-1],a[i]);
        for(int i=st+n-1,j=n-1;j>0;i--,j--)
            mx[1][j]=max(mx[1][j+1],a[i]);
        for(int i=st+1,j=1;j<n;i++,j++)
            if(mx[0][j-1]<=a[i] && mx[1][j+1]<=a[i])res--;
    }
    printf("%I64d",res);
    return 0;
}
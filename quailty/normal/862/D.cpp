#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int query(string str)
{
    printf("? %s\n",str.c_str());
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return (int)str.size()-res;
}
string build(int n,int t)
{
    string res(n,'0');
    for(int i=0;i<t;i++)
        res[i]='1';
    return res;
}
int main()
{
    int n,res[2],f,p;
    scanf("%d",&n);
    if((p=query(build(n,0)))>query(build(n,1)))res[f=0]=1;
    else res[f=1]=1;
    int l=2,r=n;
    while(l<r)
    {
        int m=(l+r)/2;
        if(abs(p-query(build(n,m)))==m)l=m+1;
        else r=m;
    }
    res[f^1]=l;
    printf("! %d %d\n",res[0],res[1]);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char s[15],t[15];
vector<int>res;
int get(char x)
{
    if(x>='0' && x<='9')return x-'0';
    else return x-'A'+10;
}
int cal(int bas,char s[])
{
    int res=0;
    for(int i=0;s[i];i++)
        res=res*bas+get(s[i]);
    return res;
}
int main()
{
    scanf("%s",s);
    int mi=0;
    for(int i=0,j=0,f=0;s[i];i++)
    {
        if(s[i]==':')
        {
            s[i]=0;
            f=1;
            continue;
        }
        mi=max(mi,get(s[i]));
        if(f==1)
        {
            t[j++]=s[i];
            s[i]=0;
        }
    }
    for(int i=mi+1;i<=61;i++)
        if(cal(i,s)<24 && cal(i,t)<60)
            res.push_back(i);
    if((int)res.empty())printf("0\n");
    else if(res.back()==61)printf("-1\n");
    else for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}
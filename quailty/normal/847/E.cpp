#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char str[MAXN];
vector<int> packmen,asterisk;
bool check(int t)
{
    int done=0;
    for(int i=0;i<(int)packmen.size() && done<(int)asterisk.size();i++)
    {
        int target=asterisk[done],right=0;
        if(target>packmen[i])
            right=packmen[i]+t;
        else
        {
            if(packmen[i]>target+t)return 0;
            right=max(right,packmen[i]+(t-packmen[i]+target)/2);
            right=max(right,2*target+t-packmen[i]);
        }
        while(done<(int)asterisk.size() && asterisk[done]<=right)done++;
    }
    return done==(int)asterisk.size();
}
int main()
{
    int n;
    scanf("%d%s",&n,str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='P')
            packmen.push_back(i);
        else if(str[i]=='*')
            asterisk.push_back(i);
    }
    int l=0,r=3*MAXN;
    while(l<r)
    {
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m+1;
    }
    printf("%d\n",l);
    return 0;
}
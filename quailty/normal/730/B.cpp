#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int>sma,big;
int query(int i,int j)
{
    printf("? %d %d\n",i,j),fflush(stdout);
    char res[5];scanf("%s",res);
    return (res[0]=='<' ? -1 : (res[0]=='=' ? 0 : 1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        sma.clear(),big.clear();
        for(int i=1;2*i<=n;i++)
        {
            if(query(2*i-1,2*i)<0)sma.push_back(2*i-1),big.push_back(2*i);
            else sma.push_back(2*i),big.push_back(2*i-1);
        }
        if(n&1)sma.push_back(n),big.push_back(n);
        for(int i=1;i<(int)sma.size();i++)
            if(query(sma[0],sma[i])>0)sma[0]=sma[i];
        for(int i=1;i<(int)big.size();i++)
            if(query(big[0],big[i])<0)big[0]=big[i];
        printf("! %d %d\n",sma[0],big[0]),fflush(stdout);
    }
    return 0;
}
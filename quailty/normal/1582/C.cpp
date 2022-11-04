#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;

int cal(int n,char str[],char ban)
{
    int res=0,i=0,j=n-1;
    while(i<j)
    {
        if(str[i]==str[j])i++,j--,res+=2;
        else if(str[i]==ban)i++;
        else if(str[j]==ban)j--;
        else return n+1;
    }
    if(i==j)res++;
    return n-res;
}

int solve()
{
    int n;
    static char str[MAXN];
    scanf("%d%s",&n,str);
    int res=n+1;
    for(int i=0;i<26;i++)
        res=min(res,cal(n,str,i+'a'));
    printf("%d\n",res<=n ? res : -1);
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
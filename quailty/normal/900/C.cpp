#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int cnt[MAXN];
int main()
{
    int n,mx[2]={0,0};
    scanf("%d",&n);
    for(int i=1,p;i<=n;i++)
    {
        scanf("%d",&p);
        if(mx[1]<p)
        {
            if(mx[0]<p)cnt[p]--;
            else cnt[mx[0]]++;
        }
        if(p>mx[0])mx[1]=mx[0],mx[0]=p;
        else if(p>mx[1])mx[1]=p;
    }
    int res=1;
    for(int i=1;i<=n;i++)
        if(cnt[i]>cnt[res])res=i;
    return 0*printf("%d\n",res);
}
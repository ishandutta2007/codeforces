#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct thing
{
    int val,num;
}s[2005];
bool cmp(thing a,thing b)
{
    return a.val==b.val ? a.num<b.num : a.val<b.val;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i].val);
        s[i].num=i;
    }
    sort(s+1,s+n+1,cmp);
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i].val==s[i-1].val)cnt++;
    }
    if(cnt>=3)
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",s[i].num);
        }
        printf("\n");
        int k=2;
        while(s[k].val!=s[k-1].val)k++;
        swap(s[k],s[k-1]);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",s[i].num);
        }
        printf("\n");
        k++;
        while(s[k].val!=s[k-1].val)k++;
        swap(s[k],s[k-1]);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",s[i].num);
        }
    }
    else printf("NO\n");
    return 0;
}
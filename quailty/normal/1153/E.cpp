#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int main()
{
    int n,rsp;
    scanf("%d",&n);
    vector<int> odd;
    for(int i=1;i<n;i++)
    {
        printf("? %d %d %d %d\n",1,1,i,n);
        fflush(stdout);
        scanf("%d",&rsp);
        if(rsp&1)odd.push_back(i);
    }
    if(!odd.empty())
    {
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            printf("? %d %d %d %d\n",1,1,odd.front(),m);
            fflush(stdout);
            scanf("%d",&rsp);
            if(rsp&1)r=m;
            else l=m+1;
        }
        int res1=l;
        l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            printf("? %d %d %d %d\n",odd.back()+1,1,n,m);
            fflush(stdout);
            scanf("%d",&rsp);
            if(rsp&1)r=m;
            else l=m+1;
        }
        int res2=l;
        printf("! %d %d %d %d\n",odd.front(),res1,odd.back()+1,res2);
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            printf("? %d %d %d %d\n",1,1,n,i);
            fflush(stdout);
            scanf("%d",&rsp);
            if(rsp&1)odd.push_back(i);
        }
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            printf("? %d %d %d %d\n",1,1,m,odd.front());
            fflush(stdout);
            scanf("%d",&rsp);
            if(rsp&1)r=m;
            else l=m+1;
        }
        int res1=l;
        l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            printf("? %d %d %d %d\n",1,odd.back()+1,m,n);
            fflush(stdout);
            scanf("%d",&rsp);
            if(rsp&1)r=m;
            else l=m+1;
        }
        int res2=l;
        printf("! %d %d %d %d\n",res1,odd.front(),res2,odd.back()+1);
    }
    return 0;
}
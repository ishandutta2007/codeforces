#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;

int n,k;

struct node{
    int l,r;
    int pos;
}a[300050];

bool cmp(node a,node b)
{
    return a.l<b.l;
}

priority_queue<int,vector<int>,greater<int> >q;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].pos=i;
    }
    int ans=0,len=0,ansl,ansr;
    sort(a+1,a+1+n,cmp);
    for(int i=1; i<=n; i++)
    {
        q.push(a[i].r);
        if(q.size()>k) 
		q.pop();
        if(q.size()==k)
            len=q.top()-a[i].l+1; 
        if(ans<len)
        {
            ans=len;
            ansl=a[i].l;
            ansr=q.top();
        }
    }
    printf("%d\n",ans);
    if(ans==0) 
        for(int i=1;i<=k;i++) 
			printf("%d ",i);
    else
    {
        for(int i=1;i<=n;i++)
        {
        	if(k==0)
        		break;
            if(a[i].l<=ansl&&a[i].r>=ansr)
            {
                printf("%d ",a[i].pos);
                k--;
            }
		}
    }
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<int>s;
int a[200005],w[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s.insert(i);
    }
    int q;
    scanf("%d",&q);
    int op,p,x;
    set<int>::iterator itr;
    while(q--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&p,&x);
            while(x>0)
            {
                itr=s.lower_bound(p);
                if(itr==s.end())break;
                p=*itr;
                if(w[p]+x>a[p])
                {
                    x-=a[p]-w[p];
                    w[p]=a[p];
                    s.erase(itr);
                }
                else
                {
                    w[p]+=x;
                    x=0;
                }
            }
        }
        else
        {
            scanf("%d",&p);
            printf("%d\n",w[p]);
        }
    }
    return 0;
}
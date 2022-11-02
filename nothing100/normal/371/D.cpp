#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch;
int n,m,a[200100],f[200100],now[200100],o,p,t;
int get(int x)
{
    if (f[x]==0) return x;
    f[x]=get(f[x]);
    return f[x];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d",&o);
        if (o==1)
        {
            scanf("%d%d",&p,&t);
            p=get(p);
            while ((t!=0)&&(p!=n+1))
            {
                if (t+now[p]<a[p])
                {
                    now[p]=now[p]+t;
                    t=0;
                }
                else
                {
                    t=now[p]+t-a[p];
                    now[p]=a[p];
                    f[p]=p+1;
                }
                p=get(p);
            }
        }
        else
        {
            scanf("%d",&p);
            printf("%d\n",now[p]);
        }
    }
    return 0;
}
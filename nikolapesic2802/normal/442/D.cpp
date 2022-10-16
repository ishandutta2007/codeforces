#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=10e6+50;
int max1[N],max2[N],par[N],res[N];
void update(int tr)
{
    int r=max1[tr];
    if(tr!=1)
        r=max(r,max2[tr]+1);
    if(r>res[tr])
    {
        res[tr]=r;
        if(par[tr]!=-1)
        {
            int sl=par[tr];
            if(max1[sl]<r)
            {
                max2[sl]=max1[sl];
                max1[sl]=r;
                update(sl);
            }
            else
            {
                if(max2[sl]<r)
                {
                    max2[sl]=r;
                    update(sl);
                }
            }
        }
    }
}
int main()
{
    for(int i=0;i<N;i++)
    {
        max1[i]=-1;
        max2[i]=-1;
        par[i]=-1;
    }
    int n;
    scanf("%i",&n);
    for(int i=2;i<=n+1;i++)
    {
        int a;
        scanf("%i",&a);
        par[i]=a;
        if(max1[a]==-1)
        {
            max1[a]=1;
        }
        else
        {
            if(max2[a]==-1)
                max2[a]=1;
        }
        res[i]=1;
        update(a);
        /*for(int i=1;i<=n;i++)
        {
            printf("%i: Max1:%i max2:%i res:%i\n",i,max1[i],max2[i],res[i]);
        }*/
        printf("%i\n",res[1]);
    }
    return 0;
}
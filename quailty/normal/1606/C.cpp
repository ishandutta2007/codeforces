#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pw[15];
int main()
{
    for(int i=(pw[0]=1);i<10;i++)
        pw[i]=10*pw[i-1];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        k++;
        static int a[15];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        ll res=0;
        for(int i=0;i+1<n;i++)
        {
            int nd=pw[a[i+1]-a[i]]-1;
            if(k<nd)res+=1LL*k*pw[a[i]],k=0;
            else res+=1LL*nd*pw[a[i]],k-=nd;
        }
        res+=1LL*k*pw[a[n-1]];
        printf("%lld\n",res);
    }
    return 0;
}
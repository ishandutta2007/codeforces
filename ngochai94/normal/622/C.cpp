#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,lis[200005],bef[200005],r,l,x;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    scanf("%d %d",&n,&m);
    For(i,1,1+n) scanf("%d",&lis[i]);
    bef[1]=0;
    For(i,2,1+n)
    {
        if(lis[i]==lis[i-1]) bef[i]=bef[i-1];
        else bef[i]=i-1;
    }
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        if(lis[r]!=x) printf("%d\n",r);
        else
        {
            if(bef[r]<l) printf("%d\n",-1);
            else printf("%d\n",bef[r]);
        }
    }
}
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

int odd,even,n,q,t,x,ans[1000006];


int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    scanf("%d %d",&n,&q);
    odd=1;even=2;
    while(q--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d",&x);
            odd+=x;
            even+=x;
            while(odd>n) odd-=n;
            while(even>n) even-=n;
            while(odd<=0) odd+=n;
            while(even<=0) even+=n;
        }
        else
        {
            if(odd&1) odd++;
            else odd--;
            if(even&1) even++;
            else even--;
        }
    }
    ans[odd] = 1;
    ans[even] = 2;
    for(int i=3;i<=n;i+=2)
    {
        odd+=2;
        if(odd>n) odd-=n;
        ans[odd] = i;
    }
    for(int i=4;i<=n;i+=2)
    {
        even+=2;
        if(even>n) even-=n;
        ans[even] = i;
    }
    For(i,1,n+1) printf("%d ",ans[i]);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
int main()
{
    while(cin>>n>>k)
    {
        ll sum=1LL*n*(n-1)/2;
        if(k>sum)
        {
            puts("Impossible");
            continue;
        }
        int now=n-1;
        while(now>=0)
        {
            sum-=now;
            if(k>sum)
            {
                ll num=k-sum;
                for(int i=1;i<=now;++i) printf("(");
                for(int i=1;i<=now-num;++i) printf(")");
                printf("()");
                for(int i=1;i<=num;++i) printf(")");
                break;
            }
            else printf("()");
            --now;
        }
        puts("");
    }
}
//0 1 2 3 4
//0 1 2 3 2
//(( (( )) ) () )
//0 1 2 3 1
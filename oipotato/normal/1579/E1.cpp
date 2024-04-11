#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
deque<int>q;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)
        {
            int x;
            scanf("%d",&x);
            if(x<q.front())q.push_front(x);else q.push_back(x);
        }
        rep(i,n)printf("%d%c",q.front()," \n"[i==n]),q.pop_front();
    }
    return 0;
}
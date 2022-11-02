#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int mx[2]={0,0};
        rep(i,2)
        {
            int n;scanf("%d",&n);
            rep(j,n){int x;scanf("%d",&x);mx[i-1]=max(mx[i-1],x);}
        }
        if(mx[0]==mx[1])puts("Alice\nBob");
        else if(mx[0]>mx[1])puts("Alice\nAlice");
        else puts("Bob\nBob");
    }
    return 0;
}
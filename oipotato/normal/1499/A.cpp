#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool check(int x,int y,int a){return a<=min(x,y)+(max(x,y)-min(x,y))/2;}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k1,k2,w,b;
        scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
        puts(check(k1,k2,w)&&check(n-k1,n-k2,b)?"YES":"NO");
    }
    return 0;
}
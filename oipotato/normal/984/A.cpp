#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int a[1010];rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf("%d\n",a[(n-1)/2+1]);
    }
    return 0;
}
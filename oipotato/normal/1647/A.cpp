#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        if(n%3==1)printf("1");
        rep(i,n/3)printf("21");
        if(n%3==2)printf("2");
        printf("\n");
    }
    return 0;
}
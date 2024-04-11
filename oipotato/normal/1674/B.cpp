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
        char s[10];scanf("%s",s);
        printf("%d\n",(s[0]-'a')*25+(s[1]-'a')-(s[1]>s[0])+1);
    }
    return 0;
}
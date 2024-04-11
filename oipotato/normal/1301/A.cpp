#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const string answer[3]={"First","Second","Friendship"};
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        char a[110],b[110],c[110];scanf("%s%s%s",a+1,b+1,c+1);
        int n=strlen(a+1);
        bool flag=1;
        rep(i,n)if(a[i]!=c[i]&&b[i]!=c[i]){flag=0;break;}
        puts(flag?"YES":"NO");
    }
    return 0;
}
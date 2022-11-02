#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    char s[55];
    scanf("%s",s+1);
    int n=strlen(s+1),cnt=0;
    rep(i,n)cnt+=s[i]=='a';
    printf("%d\n",n-max(0,n-cnt-(cnt-1)));
    return 0;
}
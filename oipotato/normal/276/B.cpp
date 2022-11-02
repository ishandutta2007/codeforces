#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[1010];
int c[26];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    rep(i,n)c[s[i]-'a']++;
    int num=0;
    rep(i,26)num+=c[i-1]&1;
    if(!num)puts("First");
    else puts(num&1?"First":"Second");
    return 0;
}
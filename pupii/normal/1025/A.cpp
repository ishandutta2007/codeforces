// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char S[100010];
int cnt[26];
main(){
    int n=gi();
    if(n==1){puts("Yes");return 0;}
    scanf("%s",S+1);
    for(int i=1;i<=n;++i)++cnt[S[i]-'a'];
    for(int i=0;i<26;++i)if(cnt[i]>1){puts("Yes");return 0;}
    puts("No");
    return 0;
}
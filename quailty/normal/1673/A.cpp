#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char str[MAXN];
int solve()
{
    scanf("%s",str+1);
    int n=strlen(str+1),tot=0;
    for(int i=1;i<=n;i++)
        tot+=str[i]-'a'+1;
    int alice=tot-(n&1 ? min(str[1]-'a',str[n]-'a')+1 : 0);
    int bob=tot-alice;
    return 0*printf("%s %d\n",(alice>bob ? "Alice" : "Bob"),abs(alice-bob));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
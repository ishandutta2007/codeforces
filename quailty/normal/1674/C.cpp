#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        char s[55],t[55];
        scanf("%s%s",s,t);
        int ls=strlen(s),lt=strlen(t);
        bool has=0;
        for(int i=0;i<lt;i++)
            has|=t[i]=='a';
        if(has)printf("%d\n",(lt>1 ? -1 : 1));
        else printf("%lld\n",1LL<<ls);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        int pos=-1;
        for(int i=n;i>1;i--)if(s[i]-'0'+s[i-1]-'0'>=10){pos=i;break;}
        if(pos!=-1)
        {
            int tmp=s[pos]-'0'+s[pos-1]-'0';
            s[pos]=tmp%10+'0';s[pos-1]=tmp/10+'0';
            puts(s+1);
        }
        else
        {
            s[2]+=s[1]-'0';
            puts(s+2);
        }
    }
    return 0;
}
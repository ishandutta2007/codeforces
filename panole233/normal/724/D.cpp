#include<cstdio>
#include<cstring>

using namespace std;

int m,anss;
char ans[100010],st[100010];
bool b[100010];
int l,r,len;

int main()
{
    scanf("%d",&m); scanf("%s",&st);
    len=strlen(st); anss=0;
    for (char ch='a'; ch<='z'; ch++)
    {
        int sum=0;
        for (int i=0; st[i]!='\0'; i++)
        {
            if (st[i]==ch||b[i]) sum=0; else sum++;
            if (sum==m) break;
        }
        if (sum==m)
        {
            for (int i=0; st[i]!='\0'; i++)
                if (st[i]==ch) ans[++anss]=ch,b[i]=1;
            continue;
        }
        l=-1; sum=0;
        for (int i=0; st[i]!='\0'; i++)
        {
            if (b[i]) sum=0; else sum++;
            if (st[i]==ch) l=i;
            if (sum==m) sum=i-l,ans[++anss]=ch;
        }
        break;
    }
    for (int i=1; i<=anss; i++) printf("%c",ans[i]);
    return 0;
}
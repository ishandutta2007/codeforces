#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[100010];
int cnt[30];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",s);
        int n=strlen(s);
        rep(j,26)cnt[j]=0;
        rep(i,n)cnt[s[i-1]-'a'+1]++;
        int pos1=-1,pos2=-1,pos3=-1,pos4=-1;
        rep(i,26)if(cnt[i]){if(pos1==-1)pos1=i;else if(pos2==-1)pos2=i;else if(pos3==-1)pos3=i;}
        rep(i,26)if(cnt[i]==1){pos4=i;break;}
        if(pos4!=-1)
        {
            putchar(pos4+'a'-1);cnt[pos4]--;
            rep(i,26)rep(j,cnt[i])putchar(i+'a'-1);
        }
        else if(pos2==-1)rep(i,cnt[pos1])putchar(pos1+'a'-1);
        else
        {
            if(cnt[pos1]-2<=n-cnt[pos1])
            {
                rep(i,min(cnt[pos1],2))putchar(pos1+'a'-1);
                int now=pos2;cnt[pos1]-=min(cnt[pos1],2);
                rep(i,cnt[pos1])
                {
                    for(;!cnt[now];now++);
                    putchar(now+'a'-1);cnt[now]--;
                    putchar(pos1+'a'-1);
                }
                for(int i=now;i<=26;i++)rep(j,cnt[i])putchar(i+'a'-1);
            }
            else if(cnt[pos2]==1||pos3!=-1)
            {
                putchar(pos1+'a'-1);cnt[pos1]--;
                putchar(pos2+'a'-1);cnt[pos2]--;
                rep(i,cnt[pos1])putchar(pos1+'a'-1);
                if(pos3!=-1)putchar(pos3+'a'-1),cnt[pos3]--;
                for(int i=pos2;i<=26;i++)rep(j,cnt[i])putchar(i+'a'-1);
            }
            else
            {
                putchar(pos1+'a'-1);cnt[pos1]--;
                rep(i,cnt[pos2])putchar(pos2+'a'-1);
                rep(i,cnt[pos1])putchar(pos1+'a'-1);
            }
        }
        puts("");
    }
    return 0;
}
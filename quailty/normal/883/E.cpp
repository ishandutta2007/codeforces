#include<bits/stdc++.h>
#define sc scanf
#define pr printf
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef double db;
typedef long long ll;

const int N=55;
const int M=1005;

char s[N],t[M][N];
bool letter[N];

int main()
{
    int n,m,cnt=0;
    sc("%d%s",&n,s);
    for(int i=0;i<n;i++)
        if(s[i]!='*') letter[s[i]-'a']=1;

    sc("%d",&m);
    while(m--)
    {
        bool f=1;
        sc("%s",t[cnt]);
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*' && s[i]!=t[cnt][i])
            {
                f=0;
                break;
            }
            if(s[i]=='*' && letter[t[cnt][i]-'a'])
            {
                f=0;
                break;
            }
        }
        if(f) cnt++;
    }
    int ans=0;
    for(int i=0;i<26;i++)
    {
        if(letter[i]) continue;
        bool f=1;
        for(int j=0;j<cnt;j++)
        {
            bool ff=0;
            for(int k=0;k<n;k++)
                if(t[j][k]==i+'a') ff=1;
            f&=ff;
        }
        ans+=f;
    }
    pr("%d\n",ans);
    return 0;
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
int p[1<<17];
int ask(int a,int b)
{
    printf("? %d %d\n",a,b);
    fflush(stdout);
    int x;scanf("%d",&x);
    return x;
}
void answer(int x){printf("! %d\n",x);fflush(stdout);}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;
        scanf("%d",&n);
        rep(i,(1<<n))p[i]=i;
        for(int i=n;i>=2;i-=2)
        {
            int cnt=0;
            for(int j=1;j<=(1<<i);j+=4)
            {
                int a=p[j],b=p[j+1],c=p[j+2],d=p[j+3];
                int tmp=ask(a,c);
                if(tmp==1)p[++cnt]=ask(a,d)==1?a:d;
                else if(tmp==2)p[++cnt]=ask(b,c)==1?b:c;
                else p[++cnt]=ask(b,d)==1?b:d;
            }
        }
        if((n&1))answer(ask(p[1],p[2])==1?p[1]:p[2]);else answer(p[1]);
    }
    return 0;
}
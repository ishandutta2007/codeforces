// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}
char in[101000];
map<string,int> XD;
int dat[12]={31,28,31,30,31,30,31,31,30,31,30,31};
inline bool valid(char* c){
    int c2=0;
    REP(i,10){
        if(c[i]=='-')c2++;
    }
    if(c2!=2)return 0;
    if(c[2]!='-'||c[5]!='-')return 0;
    int x,y,z;
    sscanf(c,"%d-%d-%d",&x,&y,&z);
    if(z<2013||z>2015)return 0;
    if(y<1||y>12)return 0;
    if(x<=0||x>dat[y-1])return 0;
    return 1;
}
int main(){
    RS(in);
    int l=strlen(in);
    REP(i,l-9){
        char c=in[i+10];
        in[i+10]=0;
        if(valid(in+i)){
            XD[in+i]++;
        }
        in[i+10]=c;
    }
    int mp=-1;
    string ans;
    FOR(it,XD){
        if(it->S>mp){
            mp=it->S;
            ans=it->F;
        }
    }
    puts(ans.c_str());
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
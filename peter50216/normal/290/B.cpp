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

char out[40][40]={
"111111101010101111100101001111111",
"100000100000000001010110001000001",
"101110100110110000011010001011101",
"101110101011001001111101001011101",
"101110101100011000111100101011101",
"100000101010101011010000101000001",
"111111101010101010101010101111111",
"000000001111101111100111100000000",
"100010111100100001011110111111001",
"110111001111111100100001000101100",
"011100111010000101000111010001010",
"011110000110001111110101100000011",
"111111111111111000111001001011000",
"111000010111010011010011010100100",
"101010100010110010110101010000010",
"101100000101010001111101000000000",
"000010100011001101000111101011010",
"101001001111101111000101010001110",
"101101111111000100100001110001000",
"000010011000100110000011010000010",
"001101101001101110010010011011000",
"011101011010001000111101010100110",
"111010100110011101001101000001110",
"110001010010101111000101111111000",
"001000111011100001010110111110000",
"000000001110010110100010100010110",
"111111101000101111000110101011010",
"100000100111010101111100100011011",
"101110101001010000101000111111000",
"101110100011010010010111111011010",
"101110100100011011110110101110000",
"100000100110011001111100111100000",
"111111101101000101001101110010001"
};
int main(){
    DRII(a,b);
    printf("%c\n",out[a][b]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
//Author: ACChampionEric
//Verdict: Accepted

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)

using namespace std;
typedef long long LL;
typedef long double LF;
const int maxn=100005;
const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const LL mod=1000000007;
const double EPS=1e-10;
const int B=270;

pair<int,int> dp[maxn][12];
int n,m,Q;
char s[maxn][12];

void build(int front,int rear)
{
    for(int i=front;i<rear;i++)
    {
        for(int j=0;j<m;j++)
            dp[i][j]=mp(i,j);
        for(int j=0;j<m;j++)
            if(s[i][j]=='^')
                dp[i][j]=i==front?mp(i-1,j):dp[i-1][j];
        for(int j=0;j<m;j++)
            if(s[i][j]=='<')
                dp[i][j]=j==0?mp(i,j-1):dp[i][j-1];
        for(int j=m-1;j>=0;j--)
            if(s[i][j]=='>')
                dp[i][j]=j==m-1?mp(i,j+1):dp[i][j+1];
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i+=B)
        build(i,min(n,i+B));
    char op[4];
    int x,y,z,nx,ny;
    while(Q--)
    {
        scanf("%s%d%d",op,&x,&y);
        x--;
        y--;
        if(op[0]=='A')
        {
            while(x>=0&&y>=0&&y<m)
            {
                nx=dp[x][y].ff;
                ny=dp[x][y].ss;
                if(nx==x&&ny>=0&&ny<m)
                {
                    x=nx;
                    y=ny;
                    break;
                }
                x=nx;
                y=ny;
            }
            if(x>=0&&y>=0&&y<m)
                x=y=-2;
            printf("%d %d\n",x+1,y+1);
        }
        else
        {
            scanf("%s",op);
            s[x][y]=op[0];
            build(x/B*B,min(n,x/B*B+B));
        }
    }
    return 0;
}
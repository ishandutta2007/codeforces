//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo                  (int)13e7
#define s(n)                    scanf("%d",&n)
#define sl(n)                   scanf("%lld",&n)
#define sf(n)                   scanf("%lf",&n)
#define fill(a,v)               memset(a, v, sizeof a)
#define ull                     unsigned long long
#define ll                      long long
#define bitcount            __builtin_popcount
#define all(x)              x.begin(), x.end()
#define pb( z )                 push_back( z )
#define gcd                 __gcd
using namespace std;

inline void read( const string &a, int& x, int& y )
{
    x = a[0] - 'a';
    y = a[1] - '1';
}

int main()
{
    string a;
    int sx, sy, ex, ey;
    cin>>a;
    read( a, sx, sy );
    cin>>a;
    read( a, ex, ey );
    
    
    
    string dir[] = { "L", "R", "U", "D", "LU", "LD", "RU", "RD" };
    int dx[] = { -1, 1, 0, 0, 0, 0, 0, 0 };
    int dy[] = {  0, 0, 1, -1,0, 0, 0, 0 };
    
    for(int d1=0; d1 < 4; d1++)
    for(int d2=d1+1; d2 < 4; d2++)
    for(int d3=4; d3 < 8; d3++)
    if( dir[d1] + dir[d2] == dir[d3] )
    {
        dx[d3] = dx[d1] + dx[d2];
        dy[d3] = dy[d1] + dy[d2];
    }
    
    
    int best = 2e9;
    vector<string> soln;
    for(int a=0; a < 4; a++)
    for(int A=0; A <= 8; A++)
    for(int b=4; b < 8; b++)
    for(int B=0; B <= 8; B++)
    {
        int cur = A+B;
        int nx = sx + A*dx[a] + B*dx[b];
        int ny = sy + A*dy[a] + B*dy[b];
        if( nx == ex && ny == ey )
        if( best > cur )
        {
            best = cur;
            soln.clear();
            for(int x=0; x < A; x++)
            soln.pb( dir[a] );
            for(int x=0; x < B; x++)
            soln.pb( dir[b] );
        }
    }
    cout<< best << endl;
    for(int i=0; i < soln.size(); i++)
    cout<< soln[i] << endl;
    
    return 0;
}
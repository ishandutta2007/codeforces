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

map<string, int> memo;

char a[4][4];

bool wins( )
{
    for(int x=0; x < 3; x++)
    for(int y=0; y < 3; y++)
    if( a[x][y] != '.' )
    for(int dx=-1; dx <= 1; dx++)
    for(int dy=-1; dy <= 1; dy++)
    if( dx || dy )
    {
        int dist = 0;
        int cx = x, cy = y;
        while( cx >= 0 && cx < 3 && cy >= 0 && cy < 3 && a[cx][cy] == a[x][y] )
        {
            cx += dx; cy += dy;
            dist++;
        }
        if( dist == 3 )
            return 1;
    }
    return 0;
}
void go( int player )
{
    string cur;
    for(int i=0; i < 3; i++)
    cur += a[i];
    //cout<< cur << endl;
    if( memo.count( cur ) ) return;
    if( wins() ) 
    {
        if( 0 && player )
        {
            for(int i=0; i < 9; i++)
            {
                cout<<cur[i];
                if( (i+1)%3 == 0 )
                cout<<endl;
            }
            cout<<"player " << player << endl << endl;
        }
        memo[ cur ] = player+2;
        
        return;
    }
    memo[ cur ] = player;
    bool nextMove = 0;
    for(int x=0; x < 3; x++)
    for(int y=0; y < 3; y++)
    if( a[x][y] == '.' )
    {
        nextMove = 1;
        a[x][y] = player ? '0' : 'X';
        go( player ^ 1 );
        a[x][y] = '.';
    }
    if( !nextMove )
    memo[cur] = 5;
}

int main()
{
    for(int i=0; i < 3; i++)
    for(int j=0; j < 3; j++)
    a[i][j] = '.';
    go( 0 );
    string x, y;
    for(int i=0; i < 3; i++)
    {
        cin>>x;
        y += x;
    }
    if( memo.count( y ) )
    {
        int res = memo[y];
        if( res <= 1 )
            cout<< ( res ? "second" : "first" ) << endl;
        else if( res==5 )
            cout<<"draw"<<endl;
        else
            cout<< ( !(res-2) ? "the second player won" : "the first player won" ) << endl;
    }
    else
        cout<<"illegal"<<endl;
    
    return 0;
}
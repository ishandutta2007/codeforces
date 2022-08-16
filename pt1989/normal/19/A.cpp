#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
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



int main()
{
    vector<string> team;
    map<string,int> score, gd, goals;
    int n;
            char D[1024];
    cin.getline( D, 1024 );
    sscanf(D,"%d",&n); 
    for(int i=0; i < n; i++)
    { cin.getline(D,1024); team.pb( D ); }
    for(int i=0; 2*i < n*(n-1); i++)
    {
        char x[256], y[256];
        int xs, ys;

        cin.getline( D, 1024 );
        for(int i=0; D[i]; i++)
            if( D[i] == '-' || D[i] == ':' ) D[i] = ' ';
        sscanf( D, "%s %s %d %d", x, y, &xs, &ys );
        if(xs==ys) score[ x ] ++, score[ y ] ++;
        else if( xs < ys ) score[y]+=3;
        else score[x]+=3;
        gd[x] += xs-ys; goals[x] += xs; goals[y] += ys;
        gd[y] += ys-xs;
    }
    
    for(int i=0; i < n; i++)
    for(int j=i+1; j <n; j++)
    if( score[ team[j] ] > score[ team[i] ] || ( score[team[j]] == score[team[i]] && gd[team[j]] > gd[team[i]] ) || ( score[team[j]] == score[team[i]] && gd[team[j]] == gd[team[i]] && goals[team[j]] > goals[team[i]] ) )
        swap( team[j], team[i] );
    sort( team.begin(), team.begin()+n/2 );
    for(int i=0; i < n/2; i++)
    cout<<team[i]<<endl;
    return 0;
}
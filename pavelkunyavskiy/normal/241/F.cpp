#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;


int n,m,k;
char s[110][110];

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

bool good(int x,int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int where(int x,int y,char c){
    for (int i = 0; i < 4; i++){
        for (int k = 1; good(x+dx[i]*k,y+dy[i]*k); k++){
            if (s[x+dx[i]*k][y+dy[i]*k] == c)
                return i;
            if (isalpha(s[x+dx[i]*k][y+dy[i]*k]))
                break;
            if (s[x+dx[i]*k][y+dy[i]*k] == '#')
                break;
        }
    }
    assert(false);
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d %d",&n,&m,&k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c",&s[i][j]);

    int curx,cury;

    scanf("%d %d ",&curx,&cury);
    --curx,--cury;

    while (true){
        char c = getc(stdin);
        if (c == ' ')
            break;
        //cerr << c << endl;
        int nap = where(curx,cury,c);
        while (s[curx][cury] != c){
            k -= (isalpha(s[curx][cury])?1:s[curx][cury]-'0');
            if (k < 0){
                cout << curx + 1 <<" "<<cury+1 << endl;
                return 0;
            }
            curx += dx[nap];
            cury += dy[nap];
        }
    }

    int tox,toy;
    scanf(" %d %d",&tox,&toy);
    --tox,--toy;

    int nap = -1;

    if (curx == tox){
        if (cury < toy)
            nap = 0;
        else
            nap = 2;
    }
    if (cury == toy){
        if (curx < tox)
            nap = 1;
        else
            nap = 3;
    }

    assert(nap != -1);

    while (curx != tox || cury != toy){
         k -= (isalpha(s[curx][cury])?1:s[curx][cury]-'0');
         if (k < 0){
            cout << curx + 1 <<" "<<cury+1 << endl;
            return 0;
         }
         curx += dx[nap];
         cury += dy[nap];            
    }

    cout << curx+1 << " "<<cury+1 << endl;      
    return 0;
}
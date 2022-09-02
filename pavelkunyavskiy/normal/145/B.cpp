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

char ans[5000000];
int ptr;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (abs(c-d) > 1){
        printf("-1\n");
        return 0;
    }
    a -= max(c+(c<=d),d);
    b -= max(c,d+(d<c));
    ptr = 0;

    if (a == -1 && c == d){
        if (b <= 0){
            printf("-1\n");
            return 0;
        }
        for (int i = 0;i < c; i++)
            ans[ptr++] = '7',ans[ptr++] = '4';
        for (int i = 0; i < b; i++)
            ans[ptr++] = '7';
        ans[ptr++] = 0;
        puts(ans);
        return 0;
    }

    if (a < 0 || b < 0){
        printf("-1\n");
        return 0;
    }


    if (d >= c){
        if (d > c)
            ans[ptr++] = '7',d--;
        a++,b++,d--,c--;
    }
    else
        a++,b++;
                    

    cerr << a << " "<<b<<" "<<d<<endl;

    for (int i = 0; i < a; i++)
        ans[ptr++] = '4';
    for (int i = 0; i < d; i++)
        ans[ptr++] = '7',ans[ptr++] = '4';
    for (int i = 0; i < b; i++)
        ans[ptr++] = '7';
    if (c == d)
        ans[ptr++] = '4';
    ans[ptr++] = 0;
    puts(ans);
  return 0;
}
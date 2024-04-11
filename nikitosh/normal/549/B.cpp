#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

const int MAXN = 205;

int a[MAXN][MAXN], p[MAXN], used[MAXN], deg[MAXN];
char s[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        gets(s);
        for (int j = 0; j < n; j++)
            if (s[j] == '0')
                a[i][j] = 0;
            else
                a[i][j] = 1;
    } 
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    while (1)
    {
        int ind = -1;
        for (int i = 0; i < n; i++)
            if (deg[i] == p[i])
            {
                ind = i;
                break;
            }
        if (ind == -1)
            break;
        used[ind] = 1;
        for (int i = 0; i < n; i++)
            if (a[ind][i])
                deg[i]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (used[i])
            cnt++;
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        if (used[i])
            printf("%d ", i + 1);
    return 0;
}
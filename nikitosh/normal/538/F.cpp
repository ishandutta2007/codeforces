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

const int MAXN = 2e5 + 5;
const int SQ = 500; 

int n;
int a[MAXN], cnt[MAXN], d[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= SQ; j++)
            if (a[i / j] > a[i + 1])
                cnt[j]++;
        for (int j = -1; j < SQ; j++)
        {
            if (a[j + 1] <= a[i + 1])
                continue; 
            int L = 0, R = 0;
            L = i / (j + 2) + 1;
            if (j == -1)
                R = n - 1;
            else
                R = i / (j + 1);
            L = max(L, SQ + 1);
            if (R >= L)
            {
                d[L]++;
                d[R + 1]--;
            }
        } 
    }    
    int cur = 0;
    for (int j = 0; j < n; j++)
    {
        cur += d[j];
        cnt[j] += cur;        
    }
    for (int i = 1; i < n; i++)
        printf("%d ", cnt[i]);
    return 0;
}
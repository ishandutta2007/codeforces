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

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n;
    scanf("%d", &n);
    string s, t;
    cin >> s >> t;
    int ind1 = -1, ind2 = -1;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
        {
            ind1 = i;
            break;
        } 
    for (int i = n - 1; i >= 0; i--)
        if (s[i] != t[i])
        {
            ind2 = i;
            break;
        } 
    if (ind1 == ind2)
    {
        puts("2");
        return 0;
    }
    int cnt = 0;
    int boo = 1;
    for (int i = ind1 + 1; i <= ind2; i++)
        if (s[i] != t[i - 1])
            boo = 0;
    if (boo)
        cnt++;

    boo = 1;
    for (int i = ind1 + 1; i <= ind2; i++)
        if (t[i] != s[i - 1])
            boo = 0;
    if (boo)
        cnt++;
    printf("%d\n", cnt);
    return 0;
}
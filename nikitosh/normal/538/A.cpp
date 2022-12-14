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

const int MAXN = 1e5 + 5;

char s[MAXN];
const char *t = "CODEFORCES";
int n, len, cnt1, cnt2;

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    gets(s);
    int n = strlen(s);
    int len = 10;
    for (int i = 0; i < min(n, len); i++)
        if (s[i] == t[i])
            cnt1++;
        else
            break;
    for (int i = n - 1; i >= 0; i--)
        if (len - n + i >= 0 && s[i] == t[len - n + i])
            cnt2++;
        else
            break;
    if (cnt1 + cnt2 >= len)
        puts("YES");
    else
        puts("NO");        
    return 0;
}
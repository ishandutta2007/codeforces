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

vector <int> ans, ANS;

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        ans.pb(n % 10);
        n /= 10;
    } 
    reverse(ans.begin(), ans.end());
    int sz = ans.size();
    int max1 = 0;
    for (int i = 0; i < sz; i++)
        max1 = max(max1, ans[i]);
    int cur = 0;
    for (int i = 0; i < max1; i++)
    {
        cur = 0;
        for (int j = 0; j < sz; j++)
        {
            cur *= 10;
            if (ans[j] > 0)
            {
                cur++;
                ans[j]--;
            }
        }
        ANS.pb(cur);
    }
    printf("%d\n", ANS.size());
    for (int i = 0; i < (int) ANS.size(); i++)
        printf("%d ", ANS[i]);
    return 0;
}
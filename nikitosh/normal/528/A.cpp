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
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

int w, h, n, l1, l2, d;
multiset <long long> s[2], len[2];
char ch;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d%d%d", &w, &h, &n);
    s[0].insert(0);
    s[0].insert(w);
    len[0].insert(w);

    s[1].insert(0);
    s[1].insert(h);
    len[1].insert(h);


    for (int i = 0; i < n; i++)
    {
        scanf(" %c%d", &ch, &d);
        int ind = 0;
        if (ch == 'H')
            ind = 1;
        auto it = s[ind].lower_bound(d);
        l1 = *it;
        it--;
        l2 = *it;
        len[ind].erase(len[ind].find(l1 - l2));
        len[ind].insert(d - l2);       
        len[ind].insert(l1 - d);
        s[ind].insert(d);
        printf("%I64d\n", *len[0].rbegin() * *len[1].rbegin());       
    } 
    return 0;
}
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

typedef complex<double> base;

const double PI = 3.1415926535897932384626433832795;
const char* sss = "ACGT";

char s[2000005], t[2000005];
set <int> Set[8];
vector <int> bad[8], v[8];
int Prev[8];

void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;
 
    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);
 
    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    //n <<= 1;
    fa.resize (n),  fb.resize (n);
 
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
 
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = int (fa[i].real() + 0.5);
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);    
    gets(s);
    gets(t);
    
    for (int i = 0; i < 4; i++)
        bad[i].resize(n);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            bad[i][j] = 1;
    for (int i = 0; i < 4; i++)
        Prev[i] = -1e9;
    for (int i = 0; i < n; i++)
    {
        Prev[strchr(sss, s[i]) - sss] = i;
        for (int j = 0; j < 4; j++)
        {
            if (i - Prev[j] <= k)
                bad[j][i] = 0;   
        }
    }

    for (int i = 0; i < 4; i++)
        Prev[i] = 1e9;
    for (int i = n - 1; i >= 0; i--)
    {
        Prev[strchr(sss, s[i]) - sss] = i;
        for (int j = 0; j < 4; j++)
        {
            if (Prev[j] - i <= k)
                bad[j][i] = 0;   
        }
    }
    
    for (int i = 0; i < 4; i++)
        v[i].resize(m);
    for (int j = 0; j < m; j++)
        v[strchr(sss, t[j]) - sss][m - j - 1] = 1;
    /*
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
                ("%d ", bad[i][j]);
        puts("");
    }
    puts("");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", v[i][j]);
        puts("");
    }
    puts("");
    */
    vector <int> ans;
    ans.resize((n + m));
    for (int i = 0; i < 4; i++)
    {
        vector <int> res;
        res.resize(n + m);
        multiply(bad[i], v[i], res);
        /*for (int j = 0; j < n + m; j++)
            printf("%d ", res[j]);
        puts("");
        */
        for (int j = 0; j < n; j++)
            ans[j] = max(ans[j], res[j]);
    }
    int cnt = 0;
    for (int i = m - 1; i < n; i++)
        if (ans[i] == 0)
            cnt++;
    printf("%d\n", cnt); 
    return 0;
}
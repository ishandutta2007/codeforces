/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int k,l;
char txt[100011],pat[100011];
int fnd[100011],fn[100011];
void comp()
{
    fn[1]=0;
    int m=0;
    for(int x=2;x<=l;x++)
    {
        while(m>0 && pat[m+1]!=pat[x])m=fn[m];
        if(pat[m+1]==pat[x])m++;
        fn[x]=m;
    }
}
int nxt[100011];
void job()
{
    int b,d,e,f,x,y,z;
    b=0;
    for(x=1;x<=k;x++)
    {
        while(b>0 && pat[b+1]!=txt[x])b=fn[b];
        if(pat[b+1]==txt[x])b++;
        if(b==l)
        {
            nxt[x] = 1;
            b=fn[b];
        }
    }
}
LL dp[100011], sum[100011], sum1[100011];
int main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    scanf("%s", txt+1), scanf("%s", pat+1);
    k = strlen(txt + 1); l = strlen(pat + 1);
    comp(); job();
    c = k + 1;
    for(int i = k-l+1; i >= 1; i--){
        if(nxt[i+l-1]) c = i+l-1;
        dp[i] = sum1[c + 1];
        if(c <= k) dp[i] = (dp[i] + k-c+1) % mod;
        sum[i] = (sum[i + 1] + dp[i]) % mod;
        sum1[i] = (sum1[i + 1] + sum[i]) % mod;
//        cout << dp[i] << " " << sum[i] << endl;
    }
    cout << sum[1] << endl;
}
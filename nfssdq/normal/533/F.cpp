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


string S, T, tS, tT;
int fnd[200001],fn[200001], l, k;
void comp()
{
    fn[1]=0;
    int m=0;
    for(int x=2;x<=l;x++)
    {
        while(m>0 && tT[m]!=tT[x-1])m=fn[m];
        if(tT[m]==tT[x-1])m++;
        fn[x]=m;
    }
}
int ar[200001];
void job()
{
    int b,d,e,f,x,y,z;
    b=0;
    for(x=1;x<=k;x++)
    {
        while(b>0 && tT[b]!=tS[x-1])b=fn[b];
        if(tT[b]==tS[x-1])b++;
        if(b==l)
        {
            ar[x-1] = 1;
            b=fn[b];
        }
    }
}

vector < int > out;
int res[200001][26], tt[200001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> l;
    cin >> S >> T;

    tS = S; tT = T;

    REP(i, 26){
        REP(j, i+1){
            set0(ar); set0(tt);

            REP(K, k){
                if(S[K] == 'a'+i) tS[K] = '1';
                else tS[K] = '0';
            }
            REP(K, l){
                if(T[K] == 'a'+j) tT[K] = '1';
                else tT[K] = '0';
            }


            comp();
            job();

            REP(K, k){
                if(ar[K]) tt[K]++;
            }

            set0(ar);

            REP(K, k){
                if(S[K] == 'a'+j) tS[K] = '1';
                else tS[K] = '0';
            }
            REP(K, l){
                if(T[K] == 'a'+i) tT[K] = '1';
                else tT[K] = '0';
            }

            comp();
            job();

            REP(K, k){
                if(ar[K] && tt[K]) {
                    res[K-l+1][i] = res[K-l+1][j] = 1;
                }
            }


        }
    }

    REP(i, k-l+1){
        int cnt = 0;
        REP(j, 26) cnt += res[i][j];
        if(cnt == 26) out.pb(i+1);
    }

    cout << out.size() << endl;
    REP(i, out.size()) cout << out[i] << " ";
    cout << endl;
}
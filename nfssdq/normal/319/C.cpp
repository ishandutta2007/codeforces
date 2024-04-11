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
#define ALL(A)     A.begin(), A.end()
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

LL M[200001];
LL B[200001];
int bad(int l1,int l2,int l3){
    return 1.0*(B[l3]-B[l1])*(M[l1]-M[l2])<1.0*(B[l2]-B[l1])*(M[l1]-M[l3]);
}
int cnt;
void insert_line(LL m,LL b){
    M[cnt]=m;
    B[cnt++]=b;
    while (cnt>=3 && bad(cnt-3,cnt-2,cnt-1)>0){
        swap(M[cnt-1],M[cnt-2]);
        swap(B[cnt-1],B[cnt-2]);
        cnt--;
    }
}
int p;
LL query(LL x)
{
    if(p>=cnt)p=cnt-1;
    while(p<cnt-1 && M[p+1]*x+B[p+1]<M[p]*x+B[p])p++;
    return M[p]*x+B[p];
}
LL A[100001], BB[100001], dp[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1) cin >> A[i];
    FOR(i, 1, a + 1) cin >> BB[i];
    insert_line(BB[1], 0);
    for(int i = 2; i <= a; i++){
        dp[i] = query(A[i]);
        insert_line(BB[i], dp[i]);
    }
    cout << dp[a] << endl;
}
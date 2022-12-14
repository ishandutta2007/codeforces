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
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
char pp[11];
int dp[12][1005][12];
int go(int lt, int lft, int dff){
    if(lft == 0)return 1;
    if(dp[lt][lft][dff] != -1)return dp[lt][lft][dff];
    dp[lt][lft][dff] = 0;
    int res = 0;
    REP(i, 10){
        if(i + 1 != lt && pp[i] == '1'  && i + 1 > dff){
            if(go(i + 1, lft - 1, i + 1 - dff) == 1){
                res = 1;
                break;
            }
        }
    }
    return dp[lt][lft][dff] = res;
}
void prnt(int lt, int lft, int dff){
    if(lft == 0)return;
    REP(i, 10){
        if(i + 1 != lt && pp[i] == '1' && i + 1 > dff && go(i + 1, lft - 1, i + 1 - dff) == 1 ){
            cout << i + 1 << " ";
            prnt(i + 1, lft - 1, i + 1 - dff);
            return;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	LL a,b,c,d,e,f,g,h,x,y,z;
	cin >> pp >> c;
	memset(dp, -1, sizeof dp);
	a = go(0, c, 0);
	if(a == 0)cout <<"NO";
	else{
        cout <<"YES"<<endl;
        prnt(0, c, 0);
	}
}
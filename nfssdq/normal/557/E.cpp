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

string s;
int dp[5001][5001], on[5001][5001];
vector < pair < string, int > > vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int k; cin >> k;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j+i < s.size(); j++){
            int l = j, r = j + i;
            if(s[l] != s[r]) continue;
            if(l+2 > r-2){
                dp[l][r] = 1;
            } else dp[l][r] = dp[l+2][r-2];
            on[l][r] = dp[l][r];
        }
    }
    for(int i = 0; i < s.size(); i++){
        vc.pb(mp(s.substr(i, s.size() - i), i));
    }
    sort(vc.begin(), vc.end());
    for(int i = 0; i < s.size(); i++){
        for(int j = s.size() - 2; j >= i; j--){
            dp[i][j] += dp[i][j+1];
        }
    }

    int l = 0, r = s.size() - 1;
    for(int t = 0; t < s.size(); t++){
        if(k <= 0 || l > r) break;
        while(l <= r && vc[l].yy+t >= s.size()) l++;
        int sum = 0, ed = l-1, sum1 = 0;
        for(int i = l; i <= r; i++){
            if(s[vc[i].yy+t] != 'a') break;
            sum += dp[vc[i].yy][vc[i].yy+t];
            ed = i;
        }
        if(sum >= k) {
            cout << "a";
            r = ed;
            for(int i = l; i <= r; i++)
                sum1 += on[vc[i].yy][vc[i].yy+t];
            if(sum1 >= k) break;
            k -= sum1;
        }
        else {
            l = ed + 1;
            cout << "b";
            k -= sum;
            for(int i = l; i <= r; i++)
                sum1 += on[vc[i].yy][vc[i].yy+t];
            if(sum1 >= k) break;
            k -= sum1;
        }
    }
    cout << endl;

}
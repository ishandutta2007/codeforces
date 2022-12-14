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
LL sum[5005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    s = "0+" + s + "+0";
    LL pre = 1, mul = 1;
    FOR(i, 2, s.size()){
        if(s[i] == '+'){
            sum[i] = mul + sum[pre];
            pre = i;
            mul = 1;
        } else if(s[i] == '*') continue;
        else mul *= s[i] - '0';
    }
    LL res = sum[s.size()-2];
    for(int i = 2; i < s.size() - 2; i += 2){
        for(int j = i; j < s.size()-2; j += 2){
            int pl = 1; LL ml = 1;
            for(int k = i - 1; k >= 1; k--){
                if(s[k] == '+') {
                    pl = k;
                    break;
                } else if(s[k] == '*') continue;
                else ml *= s[k] - '0';
            }
            int pr = s.size() - 2; LL mr = 1;
            for(int k = j + 1; k < s.size() -1; k++){
                if(s[k] == '+'){
                    pr = k;
                    break;
                } else if(s[k] == '*') continue;
                else mr *= s[k] - '0';
            }
            int ql = j; LL nl = 1;
            for(int k = i; k <= j; k++){
                if(s[k] == '+'){
                    ql = k;
                    break;
                } else if(s[k] == '*') continue;
                else nl *= s[k] - '0';
            }
            int qr = i; LL nr = 1;
            for(int k = j; k >= i; k--){
                if(s[k] == '+'){
                    qr = k;
                    break;
                } else if(s[k] == '*') continue;
                else nr *= s[k] - '0';
            }
            LL insum = 0;
            if(ql == j) insum = nl;
            else insum = sum[qr] - sum[ql] + nl + nr;
            insum *= ml * mr;
            insum += sum[pl] + sum[s.size()-2] - sum[pr];
//            if(i == 6 && j == 8) cout << pl << " " << ml << " " << pr << " " << mr << " " << insum << endl;
            res = max(res, insum);
        }
    }
    cout << res << endl;
}
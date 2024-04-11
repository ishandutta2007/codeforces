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

int Find(int x){
    int res = 0;
    while(x){
        x /= 10;
        res++;
    }
    return res;
}

int cnt[11];

int rem(int x){
    while(x){
        cnt[x%10]--;
        x /= 10;
    }
    REP(i, 10) if(cnt[i] < 0) return 0;
    return 1;
}
void add(int x){
    while(x){
        cnt[x%10]++;
        x /= 10;
    }
}

string s1, s2, res, tmp;

void go(){
    if(s2[0] > '0'){
        tmp = s2;
        REP(i, 10){
            REP(j, cnt[i]){
                tmp.pb(i+'0');
            }
        }
        if(res == "") res = tmp;
        else res = min(res, tmp);
    }
    int fl = 0;
    tmp = "";
    FOR(i, 1, 10){
        if(cnt[i]){
            tmp.pb(i+'0');
            cnt[i]--;
            fl = 1;
            break;
        }
    }
    if(fl == 0){
        return;
    }
    REP(i, 10){
        if(i >= s2[0]-'0') break;
        REP(j, cnt[i]) tmp.pb(i+'0');
    }
    tmp += s2;
    FOR(i, s2[0]-'0', 10){
        REP(j, cnt[i]) tmp.pb(i+'0');
    }

    if(res == "") res = tmp;
    else res = min(res, tmp);

    cnt[tmp[0]-'0']++;

    tmp = "";
    FOR(i, 1, 10){
        if(cnt[i]){
            tmp.pb(i+'0');
            cnt[i]--;
            break;
        }
    }
    REP(i, 10){
        if(i > s2[0]-'0') break;
        REP(j, cnt[i]) tmp.pb(i+'0');
    }
    tmp += s2;
    FOR(i, s2[0]-'0'+1, 10){
        REP(j, cnt[i]) tmp.pb(i+'0');
    }

    if(res == "") res = tmp;
    else res = min(res, tmp);

    cnt[tmp[0]-'0']++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    REP(i, s1.size()){
        cnt[s1[i]-'0']++;
    }
    REP(i, s2.size()){
        cnt[s2[i]-'0']--;
    }

    for(int i = 1; i <= s1.size(); i++){
        int len = Find(i);
        if(i+len != s1.size()) continue;
        if(rem(i)){
            if(i == 1){
                cout << s2 << endl;
                return 0;
            }
            go();
            if(res.size() == i) break;
        }
        add(i);
    }

    cout << res << endl;
}
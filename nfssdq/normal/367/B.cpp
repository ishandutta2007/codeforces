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
#define linf       (1ll<<62)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M) {
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b) {if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M) {return bigmod(a,M-2,M);}

set < pair < LL, LL > >ss, st;
LL A[2000001], B[2000001];
map < LL, LL > mm, mt;
vector < LL > res;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 0,x = 1,y,z;
    cin >> a >> b >> c;
    FOR(i, 1, a + 1)cin >> A[i];
    FOR(i, 1, b + 1)cin >> B[i];
    sort(B + 1, B + b + 1);
    mm[B[1]] = 1;
    ss.insert(mp(1, B[1]));
    FOR(i, 2, b + 1){
        if(B[i] == B[i - 1]){
            ss.erase(ss.find(mp(mm[B[i]], B[i])));
            mm[B[i]]++;
            ss.insert(mp(mm[B[i]], B[i]));
        }
        else {
            mm[B[i]] = 1;
            ss.insert(mp(1, B[i]));
        }
    }
    set < pair < LL, LL > > :: iterator it1, it2;
    FOR(i, 1, c + 1){
        if(c * (b - 1) + i > a)continue;
        st = ss;
        mt = mm;
        for(int j = i; j <= c * (b - 1) + i; j += c){
            if(j > a)goto got;
            if(st.find(mp(mt[A[j]], A[j])) != st.end())st.erase(st.find(mp(mt[A[j]], A[j])));
            mt[A[j]]--;
            st.insert(mp(mt[A[j]], A[j]));
        }
        for(int j = i; j <= a; j += c){
//                for(it1 = st.begin(); it1 != st.end(); it1++)cout << (*it1).xx << " " << (*it1).yy << endl;
            if(st.size() == ss.size()){
                it1 = st.begin();
                it2 = st.end();
                it2--;
                if((*it1).xx == 0 && (*it2).xx == 0)res.pb(j);
            }
            if(j + (c * b) > a)break;
            if(st.find(mp(mt[A[j]], A[j])) != st.end())st.erase(st.find(mp(mt[A[j]], A[j])));
            mt[A[j]]++;
            if(mm[A[j]] > 0 || mt[A[j]] != 0)st.insert(mp(mt[A[j]], A[j]));
            if(j + (c * b) <= a){
                f = A[j + (c * b)];
                if(st.find(mp(mt[f], f)) != st.end())st.erase(st.find(mp(mt[f], f)));
                mt[f]--;
                st.insert(mp(mt[f], f));
            }
        }
        got: continue;
    }
    vsort(res);
    cout << res.size() << endl;
    REP(i, res.size()) cout << res[i] << " ";
    cout << endl;
}
/*
44 11 4
4 3 3 3 4 3 4 5 1 3 4 2 4 4 2 2 1 5 3 1 5 2 3 2 4 4 5 3 2 2 2 4 2 2 2 5 4 2 3 5 4 3 1 1
4 4 1 4 4 1 2 4 2 5 4


*/
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
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
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

LL P[1000008][30], pre[1000008], lvl[1000008];
void add(int N)
{
    P[N][0] = pre[N];
    for(int y=1;(1<<y)<=1000008;y++)
        if(P[N][y-1]!=-1)P[N][y]=P[P[N][y-1]][y-1];
}
int query(int p,int q)
{
    if(lvl[p]<lvl[q])swap(p,q);
    int log,x;
    for(log=1;(1<<log)<=lvl[p];log++);
    log--;
    for(x=log;x>=0;x--)
    {
        if(lvl[p]-(1<<x)>=lvl[q])p=P[p][x];
    }
    if(p==q)return p;
    for(x=log;x>=0;x--)
    {
        if(P[p][x]!=-1 && P[p][x]!=P[q][x])
        {
            p=P[p][x];
            q=P[q][x];
        }
    }
    return pre[p];
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 2,c,d,e = 0,f = 0,g,h = 1,x,y,z;
    cin >> a;
    lvl[1] = 1;
    lvl[2] = lvl[3] = lvl[4] = 2;
    memset(P, -1, sizeof P);
    for(int i = 2; i <= 4; i++){
        pre[i] = 1;
        add(i);
    }
    d = 4; e = 2; f = 3; g = 2;
    REP(i, a){
        cin >> c;
        d++;
        lvl[d] = lvl[c] + 1;
        pre[d] = c;
        add(d);
        d++;
        lvl[d] = lvl[c] + 1;
        pre[d] = c;
        add(d);
        LL s1 = query(d, e), s2 = query(d, f);
        //cout << d << " " << e << " " << f << " " << s1 << " " << s2 << endl;
        s1 = lvl[e] + lvl[d] - 2 * lvl[s1];
        s2 = lvl[f] + lvl[d] - 2 * lvl[s2];
        x = e; h = f;
        if(s1 > g){
            x = d;
            h = e;
            g = s1;
        }
        if(s2 > g){
            x = d;
            h = f;
            g = s2;
        }
        e = x; f = h;
        cout << g << endl;
    }

}
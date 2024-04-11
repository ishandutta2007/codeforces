#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const double EPS = 1e-8;

struct quat{
    double a,b,c,d;
    quat(double a=0,double b=0,double c=0,double d=0) : a(a),b(b),c(c),d(d) {}

    quat operator + (const quat &t) const {
        return quat(a+t.a,b+t.b,c+t.c,d+t.d);
    }

    quat operator - (const quat &t) const {
        return quat(a-t.a,b-t.b,c-t.c,d-t.d);
    }

    quat operator * (const quat &t) const {
        return quat(
            a*t.a-b*t.b-c*t.c-d*t.d,
            a*t.b+b*t.a+c*t.d-d*t.c,
            a*t.c-b*t.d+c*t.a+d*t.b,
            a*t.d+b*t.c-c*t.b+d*t.a
        );
    }

    inline double len(){
        return a*a+b*b+c*c+d*d;
    }

    quat conj(){
        return quat(a,-b,-c,-d);
    }

    quat inv(){
        return conj()*quat(1.0/len());
    }
};

quat round(quat q){
    quat q1 = quat(round(q.a),round(q.b),round(q.c),round(q.d));
    quat q2 = quat(round(q.a-0.5)+0.5,round(q.b-0.5)+0.5,round(q.c-0.5)+0.5,round(q.d-0.5)+0.5);
    if((q1-q).len() < (q2-q).len()) return q1;
    return q2;
}

quat operator % (quat a,quat b){
    quat q = round(b.inv()*a);
    return a-b*q;
}

inline int sgn(double x){
    return std::fabs(x) <= EPS ? 0 : (x < 0 ? -1 : 1);
}

quat gcd(quat a,quat b){
    if(a.len() < b.len()) std::swap(a,b);
    if(!sgn(b.len())) return a;
    return gcd(b,a%b);
}

int n;
LL x[MAXN],y[MAXN],z[MAXN];
quat q[MAXN];

inline bool inZ(double x){
    return !sgn(x-round(x));
}

int main(){
    scanf("%d",&n);
    LL G = 0;
    FOR(i,1,n){
        scanf("%lld%lld%lld",x+i,y+i,z+i);
        G = std::__gcd(std::__gcd(x[i],y[i]),std::__gcd(G,z[i]));
    }
    quat g;
    FOR(i,1,n){
        x[i] /= G,y[i] /= G,z[i] /= G;
        q[i] = quat(0,x[i],y[i],z[i]);
        g = gcd(g,q[i]);
    }
    std::vector<LL> dec;LL lim = g.len();
    for(LL i = 1;i*i <= lim;++i){
        if(!(lim%i)){
            dec.pb(i);
            if(i*i != lim) dec.pb(lim/i);
        }
    }
    std::sort(all(dec));std::reverse(all(dec));
    for(auto x:dec){
        quat Q = gcd(g,quat(x));
        if(round(Q.len()) != x) continue;
        quat Qconj = Q.conj();
        quat Qprime = Q*quat(1.0/Q.len());
        quat Qprimeconj = Qprime.conj();
        bool flag = 1;
        FOR(i,1,n){
            quat t = Qprimeconj*q[i]*Qprime;
            if(!(inZ(t.b) && inZ(t.c) && inZ(t.d))){
                flag = 0;break;
            }
        }
        if(!flag) continue;
        quat r1 = Q*quat(0,1,0,0)*Qconj;
        quat r2 = Q*quat(0,0,1,0)*Qconj;
        quat r3 = Q*quat(0,0,0,1)*Qconj;
        printf("%lld\n",(LL)round(r1.len()));
        printf("%lld %lld %lld\n",(LL)round(r1.b)*G,(LL)round(r1.c)*G,(LL)round(r1.d)*G);
        printf("%lld %lld %lld\n",(LL)round(r2.b)*G,(LL)round(r2.c)*G,(LL)round(r2.d)*G);
        printf("%lld %lld %lld\n",(LL)round(r3.b)*G,(LL)round(r3.c)*G,(LL)round(r3.d)*G);
        return 0;
    }
    return 0;
}
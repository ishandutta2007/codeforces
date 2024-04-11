#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
const LD EPS = 1e-6;

inline int sgn(LD x){
    if(std::abs(x) <= EPS) return 0;
    return x > 0 ? 1 : -1;
}

struct Node{
    LD x,y;
    Node(LD x=0,LD y=0) : x(x),y(y) {}

    inline Node operator + (const Node &t) const {
        return Node(x+t.x,y+t.y);
    }

    inline Node operator - (const Node &t) const {
        return Node(x-t.x,y-t.y);
    }

    inline LD operator & (const Node &t) const {
        return x*t.x+y*t.y;
    }

    inline LD operator * (const Node &t) const {
        return x*t.y-y*t.x;
    }

    inline Node operator * (const LD &t) const {
        return Node(x*t,y*t);
    }

    inline bool operator == (const Node &t) const {
        return !sgn(x-t.x)&&!sgn(y-t.y);
    }

    inline bool operator < (const Node &t) const {
        if(x == t.x) return y < t.y;
        return x < t.x;
    }

    inline void read(){
        DB a,b;scanf("%lf%lf",&a,&b);
        x = a;y = b;
    }

    inline void print(){
        printf("(%Lf,%Lf)\n",x,y);
    }
}a[MAXN];
int n,m;

inline bool clockwise(){
    LD mn1=1e9,mn2 = 1e9;int ps = -1;
    FOR(i,1,n){
        if(sgn(mn1-a[i].x) > 0 || (!sgn(mn1-a[i].x) && sgn(mn2-a[i].y) > 0)){
            mn1 = a[i].x;mn2 = a[i].y;ps = i;
        }
    }
    int pre = ps-1,suf = ps+1;if(!pre) pre = n;
    if(suf == n+1) suf = 1;
    return sgn((a[ps]-a[pre])*(a[suf]-a[ps])) == -1;
}

struct TRI{// Triangle
    Node a,b,c;
    TRI(Node a,Node b,Node c) : a(a),b(b),c(c) {}
};

std::vector<TRI> tri;

inline bool pd1(Node s,Node t1,Node t2,Node p){
    LD x1 = (t1-s)*(p-s),x2 = (t2-s)*(p-s);
    if(sgn(x1) == sgn(x2) && sgn(x1)) return 0;
    return 1;
}

inline int intersect(Node a,Node b,Node c,Node d,Node &res){
//    a.print();b.print();c.print();d.print();
    if(!sgn((b-a)*(d-c))){
        if(!sgn((a-c)*(b-c))) return -1;
        return 0;
    }
    LD t1 = (b-a)*(c-a),t2 = (b-a)*(d-a);
    if(sgn(t1) == sgn(t2) && sgn(t1)) return 0;
    LD s1 = (b-a)*(d-c),s2 = (b-c)*(a-c),s = s2/s1;
    res = c+((d-c)*s);
    return 1;
}

inline bool pd2(Node a,Node b,Node c,Node d){
    LD l1 = std::min(a.x,b.x),r1 = std::max(a.x,b.x);
    LD l2 = std::min(c.x,d.x),r2 = std::max(c.x,d.x);
    if(std::max(l1,l2) > std::min(r1,r2)) return 0;
    l1 = std::min(a.y,b.y),r1 = std::max(a.y,b.y);
    l2 = std::min(c.y,d.y),r2 = std::max(c.y,d.y);
    if(std::max(l1,l2) > std::min(r1,r2)) return 0;
    Node t;
    return intersect(a,b,c,d,t)!=0;
}

inline bool pd3(Node a,Node b,Node c){
    return !sgn((c-a)*(b-a)) && ((c-a)&(c-b)) <= 0;
}

inline void prework(){
    std::vector<Node> q;
    FOR(i,1,n) q.pb(a[i]);
    while(SZ(q) >= 3){
        int n = SZ(q);
        FOR(i,0,SZ(q)-1){
            Node a = q[(i+n-1)%n],b = q[i],c = q[(i+1)%n];
            LD t = (b-a)*(c-b);
            if(!sgn(t)){
                q.erase(q.begin()+i);
                break;
            }
            if(sgn((b-a)*(c-a)) < 0) continue;
            bool flag = 1;
            FOR(j,0,SZ(q)-1){
//                if(j == (i+n-1)%n || j == i || j == (i+1)%n || j == (i+n-2)%n) continue;
//                int x = j,y = (j+1)%n;//Node nil;
//                flag &= !pd2(a,b,q[x],q[y]);
//                flag &= !pd2(b,c,q[x],q[y]);
//                flag &= !pd2(a,c,q[x],q[y]);
                if(j == (i+n-1)%n || j == i || j == (i+1)%n) continue; 
                bool t = pd1(a,b,c,q[j]) && pd1(b,c,a,q[j]) && pd1(c,a,b,q[j]);
                flag &= !t;
                flag &= !pd3(a,c,q[j]);
                if(!flag) break;
            }
            if(flag){
                tri.pb(TRI(a,b,c));
                q.erase(q.begin()+i);
                break;
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) a[i].read();
    if(clockwise()) std::reverse(a+1,a+n+1);
//    FOR(i,1,n) a[i].print();
    prework();
    std::map<P<Node,Node>,int> S;
    FOR(i,1,n) S[MP(a[i],a[i%n+1])] = S[MP(a[i%n+1],a[i])] = 1;
//    for(auto x:tri) x.a.print(),x.b.print(),x.c.print();
    while(m--){
        Node s,t;s.read();t.read();LD ans = 0,sm = 0;
        for(auto v:tri){
            Node a = v.a,b = v.b,c = v.c;
            Node t1,t2,t3;
//            DEBUG(intersect(s,t,a,b,t1));
//            s.print();t.print();a.print();b.print();
//            exit(0);
            int o1 = intersect(s,t,a,b,t1),o2 = intersect(s,t,b,c,t2),o3 = intersect(s,t,a,c,t3);
            if(o1 == -1 || o2 == -1 || o3 == -1){
                Node u,v;
                if(o1 == -1) u = a,v = b;
                if(o2 == -1) u = b,v = c;
                if(o3 == -1) u = a,v = c;
                if(!S[MP(u,v)]) sm += std::sqrt((u-v)&(u-v));
                else ans += std::sqrt((u-v)&(u-v));
            }
            else if(o1 || o2 || o3){
                if(o1 && o2 && o3){
                    if(t1 == t2) o1 = 0;
                    else if(t1 == t3) o1 = 0;
                    else if(t2 == t3) o2 = 0;
                }
                Node u,v;
                if(!o1) u = t2,v = t3;
                if(!o2) u = t1,v = t3;
                if(!o3) u = t1,v = t2;
                //u.print();v.print();
                ans += std::sqrt((u-v)&(u-v));
            }
//            DEBUG(ans);a.print();b.print();c.print();
        }
        ans += sm/2;
        printf("%.10f\n",(double)ans);
    }
    return 0;
}
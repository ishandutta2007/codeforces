#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define double long double
const int MAXN = 1e5 + 5;
const double pi = acos(-1);

struct Node{
    int x,y,id;double deg;
    Node(int x=0,int y=0,int id=0) : x(x),y(y),id(id){
        deg = atan2(y,x);
        //if(deg < 0) deg += 2*pi;
    }

    inline bool operator < (const Node &t) const {
        return deg < t.deg;
    }
}a[MAXN];

int n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x,y;scanf("%d%d",&x,&y);
        a[i] = Node(x,y,i);
    }
    std::sort(a+1,a+n+1);
    //FOR(i,1,n) printf("%.10f\n",a[i].deg);
    int px = -1,py = -1;double mn = 1e9;
    FOR(i,1,n){
        double x = a[i].deg,y = a[i%n+1].deg;
        if(x < y) std::swap(x,y);
        double t = std::min(x-y,2*pi-(x-y));
        if(mn > t){
            mn = t;
            px = a[i].id;
            py = a[i%n+1].id;
        }
    }
    printf("%d %d\n",px,py);
    return 0;
}
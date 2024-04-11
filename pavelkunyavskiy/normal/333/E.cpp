//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "E"

typedef long long ll;
typedef long double ld;

struct point{
    int x,y;
    point(){};
    point(int x,int y):x(x),y(y){}
};


bool cmpxy (point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool clockwise (point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool cclockwise (point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

vector<point> convex(vector<point> & a) {
    if ((int)a.size() <= 1)  return a;
    point plf = a[0],  prg = a.back();
    vector<point> up, down;
    up.push_back(plf);
    down.push_back(plf);
    for (int i = 1; i < (int)a.size()-1; i++) {
        if (clockwise (plf, a[i], prg)) {
            while ((int)up.size() >= 2 && !clockwise (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (cclockwise(plf, a[i], prg)) {
            while ((int)down.size() >= 2 && !cclockwise (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    up.push_back(prg);
    down.push_back(prg);
    vector<point> res;
    for (int i = 0; i < (int)up.size(); i++)
        res.push_back(up[i]);
    for (int i = (int)down.size() - 2; i > 0; i--)
        res.push_back(down[i]);
    return res;
}

int dist(const point& a,const point& b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool check(const vector<point>& v,int needr){
    if (v.size() <= 1) return false;
    int ptr = 0;
    int n = v.size();
    int curd = 0;
    #define next(ptr) ((ptr) == (n-1) ? 0 : (ptr)+1)
    for (int i = 0; i < n; i++){
        curd = dist(v[i], v[ptr]);
        while (true){
            int temp = dist(v[i], v[next(ptr)]);
            if (temp >= curd){
                curd = temp;
                ptr = next(ptr);
            } else break;
            if (temp >= needr) return true;
        }
    }
    #undef next
    return false;
}


int n;
vector<point> v;

bool check(int needr){
    for (int i = 0; i < n; i++){
        vector<point> nv;
        for (int j = 0; j < n; j++)
            if (dist(v[i],v[j]) >= needr)
                nv.pb(v[j]);
        if (check(convex(nv), needr)) return true;
    }
    return false;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
                    
    scanf("%d",&n);
    v.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d %d",&v[i].x,&v[i].y);
    }

    sort(v.begin(),v.end(), cmpxy);

    int L = 0;
    int R = 1e9;


    while (R - L > 1){
        int mid = (L+R)/2;
//          eprintf("L = %d; R = %d; mid = %d\n",L,R,mid);
        if (check(mid))
            L = mid;
        else
            R = mid;
    }

//      eprintf("!%d\n",L);

    printf("%.18lf\n", sqrt(L)/2.0);
      
    TIMESTAMP(end);
    return 0;
}
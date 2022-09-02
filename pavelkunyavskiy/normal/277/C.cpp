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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

int n,m;

struct Line{  
    vector<int> points;
    vector<pair<int,int> > seg;
    bool hor;
    int id;

    int getlen(){
        int ans = 0;
        int bal = 0;

        vector<pair<int,int> > evs;

        for (int i = 0; i < (int)seg.size(); i++){
            evs.pb(mp(seg[i].first,1));
            evs.pb(mp(seg[i].second,-1));
        }
        evs.pb(mp(0,0));
        evs.pb(mp(hor ? m : n, -1000));

        sort(evs.begin(),evs.end());

        points.clear();

        for (int i = 0; i < (int)evs.size(); i++){
            bal += evs[i].second;
            if (bal == 0){
                ans += evs[i+1].first - evs[i].first;
                points.pb(evs[i].first);
                points.pb(evs[i+1].first);
            }
        }
        return ans;
    }

    void getkth(int k,int& x,int& y){
        assert(k >= 0);
        x = id;
        y = -1;
        for (int i = 0; i < (int)points.size(); i += 2)
            if (k <= points[i+1] - points[i]){
                y = points[i] + k;
                break;
            }
            else {
                k -= points[i+1] - points[i];
            }
        assert(y != -1);
        if (!hor)
            swap(x,y);

    }
};

map<int,int> horid;
vector<Line> hor;
map<int,int> vertid;
vector<Line> vert;

int getid(map<int,int>& a,int b){
    if (a.find(b) == a.end()){
        int t = a.size();
        a[b] = t;
    }
    return a[b];
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    int k;
    scanf("%d",&k);

    for (int i = 0; i < k; i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1,y2);

        if (x1 == x2){
            int id = getid(horid,x1);
            if (id == (int)hor.size()){
                hor.pb(Line());
                hor.back().id = x1;
                hor.back().hor = true;
            }
            assert(id < (int)hor.size());
            hor[id].seg.pb(mp(y1,y2));
        } else {
            int id = getid(vertid,y1);
            if (id == (int)vert.size()){
                vert.pb(Line());
                vert.back().id = y1;
                vert.back().hor = false;
            }
            assert(id < (int)vert.size());
            vert[id].seg.pb(mp(x1,x2));
        }
    }

    int cnt = 2 - (n - hor.size() + 1)%2;

    for (int i = 1; i <= n-1 && cnt > 0; i++)
        if (horid.find(i) == horid.end()){
            hor.pb(Line());
            hor.back().id = i;
            hor.back().hor = true;
            cnt--;
        }

    cnt = 2 - (m - vert.size() + 1)%2;

    for (int i = 1; i <= m-1 && cnt > 0; i++)
        if (vertid.find(i) == vertid.end()){
            vert.pb(Line());
            vert.back().id = i;
            vert.back().hor = false;
            cnt--;
        }

    int g = 0;
                  
    for (int i = 0; i < (int)hor.size(); i++){
        int t = hor[i].getlen();
        eprintf("Hor %d = %d\n",i,t);
        g ^= t;
    }

    for (int i = 0; i < (int)vert.size(); i++){
        int t = vert[i].getlen();
        eprintf("Vert %d = %d\n",i,t);
        g ^= t;
    }

    if (g == 0){
        puts("SECOND");
        return 0;
    } 

    puts("FIRST");
    for (int i = 0; i < (int)hor.size(); i++){
        int t = hor[i].getlen();
        if ((t ^ g) < t){
            int x,y;
            hor[i].getkth(t-(t^g),x,y);
            printf("%d %d %d %d\n",x,0,x,y);
            return 0;
        }
    }

    for (int i = 0; i < (int)vert.size(); i++){
        int t = vert[i].getlen();
        if ((t ^ g) < t){
            int x,y;
            vert[i].getkth(t-(t^g),x,y);
            printf("%d %d %d %d\n",0,y,x,y);
            return 0;
        }
    }
      
  return 0;
}
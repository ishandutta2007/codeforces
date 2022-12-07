#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

struct ii{
    llint first;
    llint second;
    int id;
};

bool cmp(ii v, ii u){
    if(u.first == v.first) return u.second < v.second;
    return u.first < v.first;
}

llint ccw(ii u, ii v){
    return u.first * v.second - v.first * u.second;
}

ii operator -(ii u, ii v){
    v.first -= u.first;
    v.second -= u.second;
    return v;
}

ii s[N], x[N]; int ns, nx;
struct polygon{
    vector < ii > ver;

    vector<ii> graham(){
        vector<ii> result;
        sort(ver.begin(), ver.end(), cmp);

        s[++ns] = ver[0];
        for(int i = 1; i < ver.size(); ++i){
            while(ns > 1){
                ii u = s[ns] - s[ns - 1];
                ii v = ver[i] - s[ns - 1];
                if(ccw(u, v) > 0) --ns;
                else break;
            }
            s[++ns] = ver[i];
        }


        x[++nx] = s[ns];
        for(int i = ver.size() - 1; i >= 0; --i){
            while(nx > 1){
                ii u = x[nx] - x[nx - 1];
                ii v = ver[i] - x[nx - 1];
                if(ccw(u, v) > 0) --nx;
                else break;
            }
            x[++nx] = ver[i];
        }

       /* for(int i = 1; i <= nx; ++i)
            cerr << x[i].first << " " << x[i].second << endl;*/

        for(int i = 1; i <= ns; ++i)
            result.push_back(s[i]);
        for(int i = 1; i <= nx; ++i)
            result.push_back(x[i]);
        return result;
    }
}p;

int n, m;
vector < ii > cur;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        p.ver.push_back({u, v, 1});
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        p.ver.push_back({u, v, 0});
    }
    cur = p.graham();

    for(int i = 0; i < cur.size(); ++i)
        if(cur[i].id == 0){
             puts("NO");
             return;
        }
    puts("YES");
}
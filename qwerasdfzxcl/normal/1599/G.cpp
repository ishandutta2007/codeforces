#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct vector2{
    ll x, y;
    vector2(){}
    vector2(ll x, ll y): x(x), y(y){}

    ll cross(const vector2 &r)const{
        return x*r.y - y*r.x;
    }

    vector2 operator-(const vector2 &r)const{
        return vector2(x-r.x, y-r.y);
    }

    double dist(vector2 &r)const{
        return sqrt((x-r.x)*(x-r.x) + (y-r.y)*(y-r.y));
    }

    bool operator<(const vector2 &r)const{
        return make_pair(x, y) < make_pair(r.x, r.y);
    }
};

ll ccw(vector2 a, vector2 b, vector2 c){
    return (b-a).cross(c-a);
}

int n, k;
vector2 arr[200002];
vector<vector2> line;
int single;
double length;

bool check(int x, int y){
    vector<int> v;
    for(int i=1; i<=n; i++){
        if(ccw(arr[i], arr[x], arr[y]) == 0) v.push_back(i);
    }
    if((int)v.size() < n-1) return false;
    ll sum = ll(n) * ll(n+1) / 2;
    for(auto x: v) sum -= x;
    single = sum;

    for(auto x: v) line.push_back(arr[x]);
    sort(line.begin(), line.end());
    length = line[0].dist(line.back());
    return true;
}

double ans = 1e30;
vector2 p;
int s;

double solve1(){
    double ans = 1e30;

    for(int i=0; i<(int)line.size()-1; i++){
        ans = min(ans, length - line[i].dist(line[i+1]) + p.dist(line[i]) + p.dist(line[i+1]));
        ans = min(ans, length - line[i].dist(line[i+1]) + p.dist(line[i]) + p.dist(line.back()));
    }
    ans = min(ans, length + line.back().dist(p));
    ans = min(ans, length + p.dist(line[0]) + p.dist(line.back()) - line[0].dist(line[1]));

    return ans;
}

double solven(){
    double ans = 1e30;

    for(int i=0; i<(int)line.size()-1; i++){
    ans = min(ans, length - line[i].dist(line[i+1]) + p.dist(line[i]) + p.dist(line[i+1]));
        ans = min(ans, length - line[i].dist(line[i+1]) + p.dist(line[i+1]) + p.dist(line[0]));
    }
    ans = min(ans, length + line[0].dist(p));
    ans = min(ans, length + p.dist(line[0]) + p.dist(line.back()) - line.back().dist(line[s-2]));

    return ans;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }

    if(!check(1, 2)) if(!check(1, 3)) check(2, 3);
    for(int i=0; i<(int)line.size()-1; i++){
        assert(line[i].x != line[i+1].x || line[i].y != line[i+1].y);
    }

    if(k == single){
        for(vector2 x: line){
            ans = min(ans, arr[k].dist(x) + min(x.dist(line[0]), x.dist(line.back())) + length);
        }
    }
    else{
        s = (int)line.size();
        p = arr[single];
        auto it = lower_bound(line.begin(), line.end(), arr[k]);
        if(it == line.begin()){
            ans = solve1();
        }
        else if(it == prev(line.end())){
            ans = solven();
        }
        else{
            /// A->B->C
            ans = min(ans, length - it->dist(*(it+1)) + min((it+1)->dist(p), p.dist(line.back())) + p.dist(line[0]));
            /// C->B->A
            ans = min(ans, length - it->dist(*(it-1)) + min((it-1)->dist(p), p.dist(line[0])) + p.dist(line.back()));
            /// B->A->C, B->C->A
            ans = min(ans, p.dist(*it) + length + min(p.dist(line[0]), p.dist(line.back())));
            /// A->C->B
            ans = min(ans, length + it->dist(line[0]) + p.dist(line.back()));
            /// C->A->B
            ans = min(ans, length + it->dist(line.back()) + p.dist(line[0]));

            ans = min(ans, solve1() + it->dist(line[0]));
            ans = min(ans, solven() + it->dist(line.back()));
        }
    }

    printf("%.9f", ans);
}
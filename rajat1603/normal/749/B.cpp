#include "bits/stdc++.h"
using namespace std;
struct point{
    int x;
    int y;
    point(int _x = 0 , int _y = 0){
        x = _x;
        y = _y;
    }
    point operator + (const point &o) const {
        return point(x + o.x , y + o.y);
    }
    point operator - (const point &o) const {
        return point(x - o.x , y - o.y);
    }
    point operator * (const int c) const {
        return point(x * c , y * c);
    }
    point operator / (const int c) const {
        return point(x / c , y / c);
    }
    bool operator == (const point &o) const {
        return (x == o.x) && (y == o.y);
    }
    bool operator < (const point &o) const {
        return make_pair(x , y) < make_pair(o.x , o.y);
    }
};
point p1 , p2 , p3;
vector < point > v;
int main(){
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    v.clear();
    v.push_back((p2 - p1) + (p3 - p1) + p1);
    v.push_back((p3 - p2) + (p1 - p2) + p2);
    v.push_back((p1 - p3) + (p2 - p3) + p3);
    sort(v.begin() , v.end());
    v.resize(unique(v.begin() , v.end()) - v.begin());
    printf("%d\n" , int(v.size()));
    for(auto it : v){
        printf("%d %d\n" , it.x , it.y);
    }
}
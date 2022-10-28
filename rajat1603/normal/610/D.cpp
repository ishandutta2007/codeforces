#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int MAX = 3 * N;
map < int , vector < pair < int , int > > > xsame , ysame;
int n;
int a , b , c , d;
struct point{
    int type;//0 for x same start , 1 for ysame , 2 for xsame end , 
    int x;
    int y;
    int z;
    point(){
        type = 0;
        x = 0;
        y = 0;
        z = 0;
    }
    point(int a , int b , int c , int d){
        type = a;
        x = b;
        y = c;
        z = d;
    }
    bool operator < (const point &b) const{
        return make_pair(y , type) < make_pair(b.y , b.type);
    }
};
long long ans = 0;
vector < point > vv;
int bit[MAX];
void update(int idx , int val){
    while(idx < MAX){
        bit[idx] += val;
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %d %d" , &a , &b , &c , &d);
        if(a == c){
            xsame[a].emplace_back(make_pair(min(b , d) , 0));
            xsame[a].emplace_back(make_pair(max(b , d) , 1));
        }
        else{
            ysame[b].emplace_back(make_pair(min(a , c) , 0));
            ysame[b].emplace_back(make_pair(max(a , c) , 1));
        }
    }
    for(auto it : xsame){
        auto v = it.second;
        sort(v.begin() , v.end());
        int cnt = 0;
        int lst = -1;
        for(auto i : v){
            if(i.second == 0){
                ++cnt;
                if(cnt == 1){
                    lst = i.first;
                }
            }
            else{
                if(cnt == 1){
                    vv.emplace_back(point(0 , it.first , lst , -1));
                    vv.emplace_back(point(2 , it.first , i.first , -1));
                    ans += i.first - lst + 1;
                }
                --cnt;
            }
        }
    }
    for(auto it : ysame){
        auto v = it.second;
        sort(v.begin() , v.end());
        int cnt = 0;
        int lst = -1;
        for(auto i : v){
            if(i.second == 0){
                ++cnt;
                if(cnt == 1){
                    lst = i.first;
                }
            }
            else{
                if(cnt == 1){
                    vv.emplace_back(point(1 , lst , it.first , i.first));
                    ans += i.first - lst + 1;
                }
                --cnt;
            }
        }
    }
    sort(vv.begin() , vv.end());
    map < int , int > m;
    for(auto it : vv){
        m[it.x];
        if(it.type == 1){
            m[it.z];
        }
    }
    int tmp = 0;
    for(auto x : m){
        m[x.first] = ++tmp;
    }
    for(auto &it : vv){
        it.x = m[it.x];
        if(it.type == 1){
            it.z = m[it.z];
        }
    }
    for(auto it : vv){
        if(it.type == 0){
            update(it.x , 1);
        }
        else if(it.type == 2){
            update(it.x , -1);
        }
        else{
            ans -= query(it.z) - query(it.x - 1);
        }
    }
    cout << ans;
}
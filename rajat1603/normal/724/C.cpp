#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , k;
set < int > v1[N + N];
set < int > v2[N + N];
int x[N];
int y[N];
long long ans[N];
long long get(int curx , int cury , int dx , int dy , int idx){
    return abs(curx - x[idx]);
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d %d" , x + i , y + i);
        v1[x[i] + y[i]].insert(i);
        v2[x[i] - y[i] + N].insert(i);
        ans[i] = -1;
    }
    int dx = 1;
    int dy = 1;
    int curx = 0;
    int cury = 0;
    long long curtm = 0;
    for(int lol = 1 ; lol <= 4 * N ; ++lol){
        int tm;
        if(dx > 0){
            tm = n - curx;
        }
        else{
            tm = curx;
        }
        if(dy > 0){
            tm = min(tm , m - cury);
        }
        else{
            tm = min(tm , cury);
        }
        //cout << curx << " " << cury << " " << dx << " " << dy << " " << tm << endl;
        if(dx * dy == 1){
            for(auto it : v2[curx - cury + N]){
                ans[it] = curtm + get(curx , cury , dx , dy , it);
                v1[x[it] + y[it]].erase(it);
            }
            v2[curx - cury + N].clear();
        }
        else{
            for(auto it : v1[curx + cury]){
                ans[it] = curtm + get(curx , cury , dx , dy , it);
                v2[x[it] - y[it] + N].erase(it);
            }
            v1[curx + cury].clear();
        }
        int nx = curx + tm * dx;
        int ny = cury + tm * dy;
        int cnt = 0;
        if(nx == n || nx == 0){
            dx *= -1;
            ++cnt;
        }
        if(ny == m || ny == 0){
            dy *= -1;
            ++cnt;
        }
        curtm += tm;
        curx = nx;
        cury = ny;
        if(cnt > 1){
            break;
        }
    }
    for(int i = 1 ; i <= k ; ++i){
        printf("%lld\n" , ans[i]);
    }
}
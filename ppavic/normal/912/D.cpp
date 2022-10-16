#include <cstdio>
#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef long long int llint;
typedef pair < llint,llint> pii;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

llint n,m,k,r;
map < pii , llint > bio;
set < pair < llint , pii>  > s;
llint px[4] = {0,0,1,-1};
llint py[4] = {1,-1,0,0},cnt = 0;

llint cost(llint x,llint y){
    llint rl1 = min(x, n - x + 1);  
    llint rl2 = min(y, m - y + 1);
    llint rl3 = min(rl1, n - r + 1);
    llint rl4 = min(rl2, m - r + 1);
    return min(rl4,r) * min(rl3,r);
}

llint br = 0;

int main(){
    cin >> n >> m >> r >> k;
    s.insert(make_pair(cost((n+1)/2,(m+1)/2),make_pair((n+1)/2,(m+1)/2)));
    bio[make_pair((n+1)/2,(m+1)/2)] = 1;
    for(;k > 0;){
        llint c = (*(--s.end())).first;
        br += c;
        llint x = (*(--s.end())).second.first;
        llint y = (*(--s.end())).second.second;
        s.erase(--s.end());
        k--;
        for(int kk = 0;kk<4;kk++){
            llint nx = x + px[kk];
            llint ny = y + py[kk];
            if(bio[make_pair(nx,ny)]) continue;
            bio[make_pair(nx,ny)] = 1;
            s.insert(make_pair(cost(nx,ny),make_pair(nx,ny)));
        }
    }
    llint uk = (n -r + 1) * (m -r + 1);
    printf("%.14lf\n", (double)br / (double)uk);
}
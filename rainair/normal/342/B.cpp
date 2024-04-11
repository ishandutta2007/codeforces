/*
 * Author: RainAir
 * Time: 2019-07-13 09:25:51
 */
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

struct Line{
    int l,r,t;

    bool operator < (const Line &b) const {
        return t < b.t;
    }
}a[MAXN];
int n,m,s,f;
std::unordered_map<int,int> S;
std::vector<char> v;
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&f);
    FOR(i,1,m) scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
    std::sort(a+1,a+m+1);int ans = 0;
    FOR(i,1,m) S[a[i].t] = i;
    if(s <= f){
        FOR(i,s,f-1){
            ans++;if(!S[ans]){
                v.pb('R');continue;
            }
            int ps = S[ans];
            int l = a[ps].l,r = a[ps].r;
            if((l <= i && i <= r) || (i == l-1)){
                i--;v.pb('X');continue;
            }
            v.pb('R');
        }
    }
    else{
        ROF(i,s,f+1){
            ans++;if(!S[ans]){
                v.pb('L');continue;
            }
            int ps = S[ans];
            int l = a[ps].l,r = a[ps].r;
            if((l <= i && i <= r) || (i == r+1)){
                i++;v.pb('X');continue;
            }
            v.pb('L');
        }
    }
    for(auto x:v) putchar(x);
    puts("");
    return 0;
}
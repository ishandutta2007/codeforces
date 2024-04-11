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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

int n,p[MAXN],ip[MAXN];

struct Node{
    int l,r;
    Node(int l=0,int r=0) : l(l),r(r) {}

    bool operator < (const Node &t) const {
        return l < t.l;
    }
};

std::set<Node> S;
std::set<P> v;
int l[MAXN];

inline void Solve(){
    scanf("%d",&n);S.clear();v.clear();
    FOR(i,1,n) scanf("%d",p+i),ip[p[i]] = i,l[i] = i;
    FOR(i,1,n) v.insert(MP(0,i));
    FOR(j,1,n){
        int i = ip[j];
        if(l[i] == i){
            if((*v.rbegin()).fi != 0){
                puts("No");return;
            }
            Node t(i,i);v.erase(MP(i-l[i],i));
            if(S.empty()){
                S.insert(t);
                if(i == n) continue;
                v.erase(MP(i+1-l[i+1],i+1)),l[i+1] = i,v.insert(MP(i+1-l[i+1],i+1));
            }
            else{
                auto it = S.upper_bound(t),pre=it;
                if(pre != S.begin()){
                    --pre;
                    if(pre->r+1 == i) t.l = pre->l,S.erase(pre);
                }
                if(it != S.end() && it->l == i+1) t.r = it->r,S.erase(it);
                S.insert(t);
                if(t.r == n) continue;
                v.erase(MP(t.r+1-l[t.r+1],t.r+1));l[t.r+1] = t.l;v.insert(MP(t.r+1-l[t.r+1],t.r+1));
            }
        }
        else{
            if((*v.rbegin()).fi != i-l[i]){
                puts("No");return;
            }
            S.erase(Node(l[i],i-1));v.erase(MP(i-l[i],i));
            Node t = Node(l[i],i);
            if(S.empty()){
                S.insert(t);
                if(i == n) continue;
                v.erase(MP(i+1-l[i+1],i+1)),l[i+1] = l[i],v.insert(MP(i+1-l[i+1],i+1));
            }
            else{
                auto it = S.upper_bound(t);
                if(it != S.end() && it->l == i+1) t.r = it->r,S.erase(it);
                S.insert(t);
                if(t.r == n) continue;
                v.erase(MP(t.r+1-l[t.r+1],t.r+1));l[t.r+1] = t.l;v.insert(MP(t.r+1-l[t.r+1],t.r+1));
            }
        }
    }
    puts("Yes");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
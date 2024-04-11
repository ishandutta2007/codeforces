/*
 * Author: RainAir
 * Time: 2020-03-02 22:51:49
 */
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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
const int MAXM = 5e6 + 5;

int ch[MAXN][26],fail[MAXN],sm[MAXN];
int bin[MAXN],tp,tot;

inline void clr(int x){
    FOR(i,0,25) ch[x][i] = 0;fail[x] = sm[x] = 0;
}

inline int New(){
    if(!tp) return ++tot;
    clr(bin[tp]);
    return bin[tp--];
}

struct Node{
    std::vector<std::string> G;
    std::vector<int> id;
    int rt;

    inline void insert(std::string str){G.pb(str);}

    inline void Insert(std::string str){
        int v = rt;
        FOR(i,0,(int)str.length()-1){
            int x = str[i]-'a';
            if(!ch[v][x]) ch[v][x] = New(),id.pb(ch[v][x]);
            v = ch[v][x];
        }
        sm[v]++;
    }

    inline void clear(){
        for(auto x:id) bin[++tp] = x;id.clear();
//        FOR(i,1,tot) FOR(j,0,25) ch[i][j] = 0;
//        FOR(i,1,tot) fail[i] = sm[i] = 0;tot = rt = 1;
        rt = New();id.pb(rt);
    }

    inline void build(){
        clear();
        for(auto str:G) Insert(str);
        std::queue<int> q;
        FOR(i,0,25){
            if(ch[rt][i]) fail[ch[rt][i]] = rt,q.push(ch[rt][i]);
            else ch[rt][i] = rt;
        }
        while(!q.empty()){
            int v = q.front();q.pop();
            sm[v] += sm[fail[v]];
            FOR(i,0,25){
                if(ch[v][i]) fail[ch[v][i]] = ch[fail[v]][i],q.push(ch[v][i]);
                else ch[v][i] = ch[fail[v]][i];
            }
        }
    }

    inline int query(std::string str){
        //DEBUG(tot);
        if(tot == 1) return 0;
        int v = rt;int ans = 0;
        FOR(i,0,(int)str.length()-1){
            v = ch[v][str[i]-'a'];
            ans += sm[v];
        }
        return ans;
    }
}A[20],B[20];
int tp1,tp2;

int main(){
    std::ios::sync_with_stdio(false);
    int T;std::cin >> T;
    while(T--){
        int opt;std::string str;std::cin >> opt >> str;
        if(opt == 1){
            A[++tp1].clear();A[tp1].G.clear();A[tp1].insert(str);
            while(tp1 > 1 && A[tp1].G.size() == A[tp1-1].G.size()){
                for(auto x:A[tp1].G) A[tp1-1].insert(x);
                A[tp1].G.clear();A[tp1--].clear();
            }
            A[tp1].build();
        }
        if(opt == 2){
            B[++tp2].clear();B[tp2].G.clear();B[tp2].insert(str);
            while(tp2 > 1 && B[tp2].G.size() == B[tp2-1].G.size()){
                for(auto x:B[tp2].G) B[tp2-1].insert(x);
                B[tp2].G.clear();B[tp2--].clear();
            }
            B[tp2].build();
        }
        if(opt == 3){
            int ans = 0;
            FOR(i,1,std::max(tp1,tp2)) ans += A[i].query(str)-B[i].query(str);
            std::cout << ans << '\n';std::fflush(stdout);
        }
    }
    return 0;
}
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define Re register
#define LL long long
#define MP std::make_pair
#define P std::pair<int,int>
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000+5;
char str[MAXN];
int N;
int next[MAXN],last[MAXN];
bool vis[MAXN];

inline void add(int u,int v){
    next[u] = v;last[v] = u;
}

inline int calc(char x){
    return x == 'R';
}

std::queue<int> q[2];
std::vector<P> seq;

bool upd(){
    int sz = (int)seq.size()-1;
    if(sz < 1) return false;
    int st = seq[sz].fi,ed = seq[sz].se,st2 = seq[sz-1].fi,ed2 = seq[sz-1].se;
    if(str[ed] != str[st2]){
        add(ed,st2);seq.pop_back();
        seq.back() = MP(st,ed2);
        return true;
    }
    if(str[ed2] != str[st]){
        add(ed2,st);seq.pop_back();
        seq.back() = MP(st2,ed);
        return true;
    }
    if(str[st] != str[ed]){
        if(ed >= ed2){
            std::swap(st,st2);
            std::swap(ed,ed2);
        }
        int z = last[ed2];
        add(ed,ed2);add(ed2,st2);
        next[z] = 0;seq.pop_back();
        seq.back() = MP(st,z);
        return true;
    }
    return false;
}

int main(){
    scanf("%s",str+1);N = strlen(str+1);
    FOR(i,1,N){
        int x = str[i] == 'R';
        if(!q[x^1].empty()){
            add(q[x^1].front(),i);
            vis[i] = true;q[x^1].pop();
        }
        q[x].push(i);
    }
    int cnt = -1;
    FOR(i,1,N){
        if(!vis[i]){
            ++cnt;int ed = i;
            while(next[ed]) ed = next[ed];
            seq.push_back(MP(i,ed));
            while(upd());
        }
    }
    printf("%d\n",cnt);
    FOR(i,0,(int)seq.size()-1){
        int v = seq[i].fi;
        while(v){
            if(i || v != seq[i].fi) printf(" ");
            printf("%d",v);
            v = next[v];
        }
    }
    puts("");
    return 0;
}
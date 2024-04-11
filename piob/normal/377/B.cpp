#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <complex>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long LL;

int n, m, s, cs;

const int MAXN = 100010;
const int MAXM = 100010;


struct student{
    int i, cost, skill;
};

inline bool cmp(const student &a, const student &b){
    return a.skill > b.skill;
}

int who[MAXM];
student S[MAXN];
PII W[MAXM];
priority_queue<PII> Q;

bool check(int d){
    cs = s;
    int j = 0;
    int i = 0;
    int cc, ci, cd;
    while(!Q.empty()) Q.pop();
    while(j < m){
        while(i < n && S[i].skill >= W[j].x){
            Q.push(PII(-S[i].cost, S[i].i));
            ++i;
        }
        if(Q.empty())
            return 0;
        cc = -Q.top().x;
        ci = Q.top().y;
        Q.pop();
        cs -= cc;
        if(cs < 0) return 0;
        cd = d;
        while(cd && j < m){
            --cd;
            who[W[j].y] = ci;
            ++j;
        }
    }
    return 1;
}

int main(){
    scanf("%d %d %d", &n, &m, &s);
    FWD(i,0,m){
        scanf("%d", &W[i].x);
        W[i].y = i;
    }   
    sort(W, W+m);
    reverse(W, W+m);
    FWD(i,0,n){
        scanf("%d", &S[i].skill);
        S[i].i = i+1;
    }
    FWD(i,0,n)
        scanf("%d", &S[i].cost);
    sort(S, S+n, cmp);
    if(S[0].skill < W[0].x){
        printf("NO\n");
        return 0;
    }
    int p = 0;
    int k = m;
    while(k-p>1){
        if(check((p+k)/2))
            k = (p+k)/2;
        else
            p = (p+k)/2;
    }
    if(!check(k)){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    FWD(i,0,m) printf("%d ", who[i]);
    printf("\n");
    return 0;
}
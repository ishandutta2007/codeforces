#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <limits>
#include <iostream>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PDD pair<double, double>
#define x first
#define y second
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
    #define debug printf
#else
    #define debug
#endif

using namespace std;

vector<pair<long long, int> > S, P;
vector<int> C[1010];
long long res, mi;
int st;

int main(){
    int k, n, a, b;
    scanf("%d %d", &n, &k);
    FWD(i,1,n+1){
        scanf("%d %d", &a, &b);
        if(b == 1)
            S.push_back(PII(a,i));
        else
            P.push_back(PII(a,i));
    }
    sort(S.begin(), S.end());
    sort(P.begin(), P.end());
    a = k-1;
    while(a != 0 && !S.empty()){
        C[a].push_back(S.back().y);
        res += S.back().x;
        S.pop_back();
        --a;
    }
    while(a != 0){
        C[a].push_back(P.back().y);
        res += 2*P.back().x;
        P.pop_back();
        --a;
    }
    mi = 1000000000;
    st = 0;
    while(!S.empty()){
        C[0].push_back(S.back().y);
        res += 2*S.back().x;
        mi = min(mi, S.back().x);
        st = 1;
        S.pop_back();
    }
    while(!P.empty()){
        C[0].push_back(P.back().y);
        res += 2*P.back().x;
        mi = min(mi, P.back().x);
        P.pop_back();
    }
    if(st)
        res -= mi;
    cout << (res/2LL);
    cout << ".";
    cout << ((res&(1LL))?5:0);
    cout << endl;
    FWD(i,0,k){
        cout << C[i].size() << " ";
        FE(c, C[i])
            cout << (*c) << " ";
        cout << endl;
    }
    return 0;
}
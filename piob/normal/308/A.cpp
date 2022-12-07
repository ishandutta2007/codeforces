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

int N, L, T;
int P[1000010];
double r, c;

void dec(int &i){
    if(i == 0)
        i = N-1;
    else
        --i;
}

void inc(int &i){
    if(i == N-1)
        i = 0;
    else
        ++i;
}

int main(){
    scanf("%d %d %d", &N, &L, &T);
    FWD(i,0,N){
        scanf("%d", &P[i]);
    }
    FWD(i,0,N)
        c += (N-1)/4.0; 
    r += ((int)(T/L)) * 2 * c;
    T = (T % L);
    
        int k = 1;
        FWD(i,0,N){
            while((k!=i) && (P[k] - P[i] + L)%L + L <= 2*T)
                inc(k);
            r += ((k-i+2*N-1)%N)/4.0;
            if(i + 1 == k) inc(k);
        }

        k = 1;
        FWD(i,0,N){
            while((k!=i) && (P[k] - P[i] + L)%L <= 2*T)
                inc(k);
            r += ((k-i+2*N-1)%N)/4.0;
            if(i + 1 == k) inc(k);
        }
    
    printf("%.6lf\n", r);
    return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int T[(1<<20)+3];
LL inv[23], sum[23], same[23];

void merge_sort(int S[], int k, int h){
    if(k == 1) return;
    merge_sort(S, k/2, h+1);
    merge_sort(S+k/2, k/2, h+1);
    int R[k];
    int a = 0, b = 0;
    while(a < k/2 && b < k/2){
        if(S[a] > S[b+k/2]){
            R[a+b] = S[b+k/2];
            ++b;
            inv[h] += k/2 - a;
        }else{
            R[a+b] = S[a];
            ++a;
        }
    }
    while(a < k/2){
        R[a+b] = S[a];
        ++a;
    }
    while(b < k/2){
        R[a+b] = S[b+k/2];
        ++b;
    }
    sum[h] += (LL)(k/2) * (k/2);
    int c = 0, v = -1;
    FWD(i,0,k){
        S[i] = R[i];
        if(R[i] == v)
            ++c;
        else{
            same[h] += (LL)c * (c-1) / 2;
            v = R[i];
            c = 1;
        }
    }
    same[h] += (LL)c * (c-1) / 2;
}

int main(){
    scanf("%d", &n);
    int p = n;
    n = (1 << n);
    FWD(i,0,n)
        scanf("%d", &T[i]);
    merge_sort(T, n, 0);
    LL res = 0;
    FWD(i,0,p)
        res += inv[i];
    FWD(i,0,p)
        sum[i] = sum[i] - same[i] + same[i+1];
    int m, q;
    scanf("%d", &m);
    FWD(i,0,m){
        scanf("%d", &q);
        q = p - q;
        FWD(j,q,p){
            res = res + sum[j] - 2*inv[j];
            inv[j] = sum[j] - inv[j];
        }
        cout << res << endl;
    }
    return 0;
}
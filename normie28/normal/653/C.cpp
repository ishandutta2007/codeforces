#include <bits/stdc++.h>
using namespace std;
#define FILE_IN "pviz.in"
#define FILE_OUT "pviz.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define boring_mod 10007
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define endl "\n"
typedef unsigned long long int ull;
typedef long long int ll;
typedef int num;
 
#ifndef ONLINE_JUDGE
#define DEBUG(...) {fprintf(stderr, __VA_ARGS__);}
#else
#define DEBUG(...) {}
#endif
 
const int N = 200007;
 
int n;
int a[N];
bool ch[N], cc;
 
int cntBad(int i, bool rf) {
    int res = 0;
    if (i < n-1) {
        if (i&1) {
            if (a[i] <= a[i+1])
                res++;
        } else {
            if (a[i] >= a[i+1])
                res++;
        }
    }
    if (i && rf)
        res += cntBad(i-1, 0);
    return res;
}
 
int main () {
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
 
    int cnt = 0;
    int fs = -1;
    for (int i = 0; i < n; i++) {
        cnt += cntBad(i, 0);
        if (fs == -1 && cntBad(i, 0))
            fs = i;
    }
    int ls = min(fs+1, n-1);
    assert(fs >= 0);
    assert(cnt >= 0);
    int res = 0;
    bool ch = 0;
    while (fs <= ls) {
        for (int i = 0; i < n; i++) {
            if (fs != ls && i == fs+1)
                continue;
            int ccn = cnt;
            if (abs(i-fs) <= 1) {
                if (i == fs) continue;
                swap(a[i], a[fs]);
                ccn = 0;
                for (int j = 0; j < n; j++)
                    ccn += cntBad(j,0);
                swap(a[i], a[fs]);
            } else {
                ccn -= cntBad(i,1);
                ccn -= cntBad(fs,1);
                swap(a[i], a[fs]);
                ccn += cntBad(i,1);
                ccn += cntBad(fs,1);
                swap(a[i], a[fs]);
            }
            assert(ccn >= 0);
            if (ccn == 0)
                res++;
        }
        fs++;
    }
    printf("%d\n", res);
}
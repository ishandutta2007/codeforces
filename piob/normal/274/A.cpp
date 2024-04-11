#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
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

int n;
LL k;
LL T[100010];
set<LL> S;

int main(){
    cin >> n >> k;
    FWD(i,0,n) cin >> T[i];
    sort(T, T+n);
    reverse(T, T+n);
    FWD(i,0,n)
        if(S.find(T[i]*k) == S.end())
            S.insert(T[i]);
    cout << S.size() << endl;
    return 0;
}
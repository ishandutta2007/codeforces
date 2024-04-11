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

int n, w;
LL p, h;
vector<LL> S;

int main(){
    cin >> n;
    FWD(i,0,n){
        cin >> p;
        S.push_back(p);
    }
    p = 0;
    cin >> n;
    FWD(i,0,n){
        cin >> w >> h;
        cout << max(p, S[w-1]) << endl;
        p = max(p, S[w-1]) + h;
    }
    return 0;
}
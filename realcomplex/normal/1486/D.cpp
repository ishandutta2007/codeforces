#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];

int n, k;
int pf[N];

bool check(int m){
    int cur;
    int best = -(int)1e9;
    for(int i = 1; i <= n; i ++) {
        if(A[i] >= m) cur = +1;
        else cur = -1;
        pf[i] = pf[i - 1] + cur;
        if(i >= k)
            best = max(best, -pf[i-k]);
        if(pf[i] + best > 0){
            return true;
        }
    }
    return false;
}

int main(){
    fastIO;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    int li = 1, ri = n + 1;
    int mid;
    while(li + 1 < ri){
        mid = (li + ri) / 2;
        if(check(mid))
            li = mid;
        else
            ri = mid;
    }
    cout << li << "\n";
    return 0;
}
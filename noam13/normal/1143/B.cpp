#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=1e18;

int maxP(int n){
    if (n==0) return 1;
    if (n<10) return n;
    int p=n%10;
    n/=10;
    return max(p*maxP(n),9*maxP(n-1));
}

int32_t main(){
    int n;cin>>n;
    cout << maxP(n)<<endl;
    return 0;
}
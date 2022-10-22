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

int32_t main(){
    int n,l=-1,r=-1,a;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if (a==1) l=i;
        else r=i;
    }
    cout << min(l,r)+1<<endl;
    return 0;
}
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <map>
#define MAX 100000
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
#include <iostream>
#include <algorithm>
using namespace std;
int A[300000];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int ans = inf;
    for(int i=0;i<n;i++){
        int dis = max(i, n-1-i);
        ans = min(ans, A[i]/dis);
    }
    cout << ans;
    return 0;
}
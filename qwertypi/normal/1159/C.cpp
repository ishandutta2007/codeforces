#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <numeric>
#include <map>
#define MAX 100000
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;
int A[100000];
int B[100000];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<m;i++){
        cin >> B[i];
    }
    if(*max_element(A, A+n) > *min_element(B, B+m)){
        cout << -1;
    }else{
        ll ans = accumulate(A, A+n, 0LL) * m;
        sort(A, A+n);
        ans += accumulate(B, B+m, 0LL) - (ll)A[n-1] * m;
        if(all_of(B, B+m, [&n](int k){return k != A[n-1];})){
            ans -= A[n-2] - A[n-1];
        }
        cout << ans;
    }
    return 0;
}
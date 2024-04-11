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

int A[200000];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    sort(A, A+n);
    int ind = 0;
    int ans = 0;
    while(true){
        if(ind == n){
            break;
        }
        if(A[ind] > ans){
            ans++;
        }
        ind++;
    }
    cout << ans;
    return 0;
}
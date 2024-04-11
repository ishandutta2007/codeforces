#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <numeric>
#include <map>
#include <math.h>
#define MAX 200002
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
#define m1 998244353
#define epi 1e-12
#define NO "IMPOSSIBLE"
#define Ans(i, n) cout << "Case #" << i << ": " << n << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

set<int> reached;

bool A[200000];
int main(){
    int n, b, a, max_A;
    cin >> n >> b >> max_A;
    a = max_A;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(A[i]){
            if(b && a != max_A){
                b--; a++;
            }else if(a){
                a--;
            }else if(b){
                b--;
            }else{
                break;
            }
        }else{
            if(a){
                a--;
            }else if(b){
                b--;
            }else{
                break;
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
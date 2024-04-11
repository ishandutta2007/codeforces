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

set<int> numbers;
vector<int> value;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        numbers.insert(v);
    }
    value = vector<int>(numbers.begin(), numbers.end());
    sort(value.begin(), value.end());
    int cnt = numbers.size();
    if(cnt == 1){
        cout << 0;
    }else if(cnt == 2){
        int diff = value[1] - value[0];
        if(diff % 2 == 1){
            cout << diff;
        }else{
            cout << diff / 2;
        }
    }else if(cnt == 3){
        int diff_1 = value[1] - value[0];
        int diff_2 = value[2] - value[1];
        if(diff_1 != diff_2){
            cout << -1;
        }else{
            cout << diff_1;
        }
    }else{
        cout << -1;
    }
    return 0;
}
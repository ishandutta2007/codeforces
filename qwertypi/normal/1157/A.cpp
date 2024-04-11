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

int f(int x){
    x++;
    while(x % 10 == 0){
        x /= 10;
    }
    return x;
}

int main(){
    int x;
    cin >> x;
    while(reached.find(x) == reached.end()){
        reached.insert(x);
        x = f(x);
    }
    cout << reached.size();
    return 0;
}
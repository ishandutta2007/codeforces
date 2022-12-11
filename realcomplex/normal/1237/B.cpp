#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int B[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int b;
    for(int i = 0 ; i < n; i ++ ){
        cin >> b;
        B[b] = i;
    }
    set<int> pos;
    int res = 0;
    for(int i = 0 ; i < n; i ++ ){
        auto it = pos.lower_bound(B[a[i]]);
        if(it != pos.end()){
            res ++ ;
        }
        pos.insert(B[a[i]]);
    }
    cout << res << "\n";
    return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

#define MAX_N 1000015

vector<int> prime;
bool is_prime[MAX_N];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int res[1000010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sieve(1000010);
    int k = 0;
    for(int i=1;i<=1000000;i++){
        res[i] += res[i-1];
        if(is_prime[i]||i==1){
            res[i]++;
        }
        if(prime[k]*prime[k]<=i){
            res[i]--;
            k++;
        }
    }
    // for(int i=1;i<=30;i++){
    //     cout << i << " " << res[i] << endl;
    // }
    int t;
    cin >> t;
    rep(i,t){
        int n;
        cin >> n;
        cout << res[n] << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#pragma optimize("Ofast")
#pragma unroll
#define int long long
using namespace std;
int prec[200001];
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
 
unordered_map<long long, int, custom_hash> A;
int _max[200001];
 
inline long long f(int x, int y){
	return (long long) x + (y << 30);
}

int32_t main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> _max[i];
		prec[i] = _max[i];
	}
	cin >> q;
	long long ans = accumulate(prec + 1, prec + n + 1, 0LL);
	int v1, v2, k;
	long long id;
	for(int i = 0; i < q; i++){
		cin >> v1 >> v2 >> k;
		id = f(v1, v2);
		if(A[id]){
			ans += prec[A[id]]++ >= 0;
			A[id] = 0;
		}
		if(k){
		    ans -= prec[k]-- >= 1;
			A[id] = k;
		}
	
		cout << ans << endl;
	}
}
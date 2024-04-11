#include <bits/stdc++.h>
#define int long long

using namespace std;

int A[300010];

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

struct inversion{
	int cnt_0 = 0, cnt_1 = 0, inv = 0;
	inline void update(int x){
		if(x){
			cnt_1++;
		}else{
			inv += cnt_1;
			cnt_0++;
		}
	}
	
	void print(){
		cout << cnt_0 << ' ' << cnt_1 << ' ' << inv << endl;
	}
};

unordered_map<long long, inversion, custom_hash> safe_map;
inversion B[1048576]; // #inv, #0, #1
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int b = 0;
	int x = 0, y = 0;
	
	int total = 0;
	for(int j = 29; j >= 11; j--){
		for(int i = 0; i < n; i++){
			x = (A[i] >> j) % 2;
			y = (A[i] >> j + 1);
			B[y].update(x);
		}
		
		int res = 0, all = 0;
		for(int i = 0; i < (1 << 29 - j); i++){
			res += B[i].inv;
			all += B[i].cnt_0 * B[i].cnt_1;
		}
		
		if(res > all / 2){
			b += (1 << j);
			total += all - res;
		}else{
			total += res;
		}
		
		fill(B + 0, B + (1 << 29 - j), inversion());
	}
	
	for(int j = 10; j >= 0; j--){
		for(int i = 0; i < n; i++){
			x = (A[i] >> j) % 2;
			y = (A[i] >> j + 1);
			safe_map[y].update(x);
		}

		int res = 0, all = 0;
		for(auto i : safe_map){
			res += i.second.inv;
			all += i.second.cnt_0 * i.second.cnt_1;
		}
		
//		for(auto i : safe_map){
//			i.second.print();
//		}
//		
//		cout << res << ' ' << all << endl;
//		cout << "++++++++++" << endl;
		if(res > all / 2){
			b += (1 << j);
			total += all - res;
		}else{
			total += res;
		}
		
		
		safe_map.clear();
	}
	
	cout << total << ' ' << b << endl;
}

int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}
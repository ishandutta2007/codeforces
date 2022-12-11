#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

struct Tree{
	int nn;
	int vl[N * 2];
	
	void upd(int idx, int val){
		idx += nn;
		vl[idx] = val;
		idx /= 2;
		while(idx > 0){
			vl[idx] = max(vl[idx * 2], vl[idx * 2 + 1]);
			idx /= 2;
		}
	}
	
	int query(int a, int b){
		int ret = -(int)1e9;
		a += nn;
		b += nn;
		while(a <= b){
			if(a % 2 == 1) ret = max(ret, vl[a ++ ]);
			if(b % 2 == 0) ret = max(ret, vl[b -- ]);
			a /= 2;
			b /= 2;
		}
		return ret;
	}
	
	void init(int ni){
		nn = ni;
		for(int i = 0 ;i <= ni * 2; i ++ ){
			vl[i] = -(int)1e9;
		}
	}
};

Tree points[32];

int main(){
	fastIO;
	int n, k;
	cin >> n >> k;
	for(int t = 0; t < 32; t ++ ){
		points[t].init(n);
	}
	int c[k];
	int sum;
	for(int i = 0 ; i < n; i ++ ){
		for(int j = 0 ; j < k ; j ++ ){
			cin >> c[j];
		}
		for(int z = 0; z < (1 << k); z ++ ){
			sum = 0;
			for(int bit = 0; bit < k; bit ++ ){
				if((1 << bit) & z){
					sum += c[bit];
				}
				else{
					sum -= c[bit];
				}
			} 
			points[z].upd(i, sum);
		}
	}
	int qr;
	cin >> qr;
	int type;
	int index;
	int lef, rig;
	int answer;
	int mx = (1 << k) - 1;
	for(int query = 0; query < qr; query ++ ){
		cin >> type;
		if(type == 1){
			cin >> index;
			-- index;
			for(int l = 0; l < k ; l ++ )
				cin >> c[l];
			for(int z = 0; z < (1 << k); z ++ ){
				sum = 0;
				for(int bit = 0; bit < k; bit ++ ){
					if((1 << bit) & z){
						sum += c[bit];
					}
					else{
						sum -= c[bit];
					}
				}
				points[z].upd(index, sum);
			}
		}
		else{
			cin >> lef >> rig;
			-- lef, -- rig;
			answer = -(int)1e9;
			for(int z = 0; z < (1 << k); z ++ ){
				answer = max(answer, points[z].query(lef, rig) + points[mx - z].query(lef, rig));
			}
			cout << answer << "\n";
		}
	}
	return 0;
}
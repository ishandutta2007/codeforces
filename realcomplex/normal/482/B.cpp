#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int BIT = 30;

int cnt[N][BIT];

int calc_AND(int cl, int cr){
	int siz = cr - cl + 1;
	int sum = 0;
	for(int j = 0 ; j < BIT; j ++ ){
		if(cnt[cr][j] - cnt[cl - 1][j] == siz){
			sum |= (1 << j);
		}
	}
	return sum;
}

int main(){
	fastIO;
	int n, q;
	cin >> n >> q;
	int cl[q], cr[q], ki[q];
	for(int i = 0 ;i < q; i ++ ){
		cin >> cl[i] >> cr[i] >> ki[i];
		for(int j = 0 ; j < BIT; j ++ ){
			if(ki[i] & (1 << j)){
				cnt[cl[i]][j] ++;
				cnt[cr[i] + 1][j] --  ;
			}
		}
	}
	for(int i = 1; i <= n; i ++ ){
		for(int j = 0 ; j < BIT; j  ++ ){
			cnt[i][j] += cnt[i - 1][j];
		}
	}
	for(int i = 1; i <= n; i ++ ){
		for(int j = 0 ; j < BIT; j ++ ){
			cnt[i][j] = min(cnt[i][j], 1);
		}
	}
	for(int i = 1; i <= n; i ++ ){
		for(int j = 0 ; j < BIT;j ++ ){
			cnt[i][j] += cnt[i - 1][j];
		}
	}
	for(int i = 0 ; i < q; i ++ ){
		if(calc_AND(cl[i], cr[i]) != ki[i]){
			cout << "NO\n";
			exit(0);
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i ++ ){
		cout << calc_AND(i, i) << " ";
	}
	return 0;
}
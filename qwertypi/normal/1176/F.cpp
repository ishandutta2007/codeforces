#include <iostream>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

const int costs[] = {1, 1, 1, 2, 3};
long long dp[200001][10];
void round_update(int n){
	int card;
	cin >> card;
	int val[5] = {0, 0, 0, 0, 0};
	for(int i=0;i<card;i++){
		int cost, damage;
		cin >> cost >> damage;
		switch(cost){
			case 1:
				if(damage > val[0]){
					val[0] = damage;
					sort(val, val+3);
				}
				break;
			case 2:
				val[3] = max(val[3], damage);
				break;
			case 3:
				val[4] = max(val[4], damage);
				break;
		}
	}
	for(int bit=0; bit < (1 << 5); bit++){
		int cnt = bit;
		bool states[5];
		for(int i=0;i<5;i++){
			bool state = cnt % 2;
			cnt /= 2;
			states[i] = state && (val[i] != 0);
		}
		int n_card = 0;
		int cost = 0;
		long long damage = 0;
		long long max_damage = 0;
		for(int i=0;i<5;i++){
			if(states[i]){
				cost += costs[i];
				damage += val[i];
				max_damage = max(max_damage, (long long)val[i]);
				n_card++;
			}
		}
		if(cost > 3){
			continue;
		}
		for(int i=0;i<10;i++){
			if(i == 0 || dp[n-1][i]){
				if(i + n_card >= 10){
					dp[n][(i + n_card) % 10] = max(dp[n][(i + n_card) % 10], dp[n-1][i] + damage + max_damage);
				}else{
					dp[n][i + n_card] = max(dp[n][i + n_card], dp[n-1][i] + damage);
				}
			}
		}
	}
}
int main(){
	for(int i=0;i<=200000;i++){
		fill(dp[i], dp[i]+10, 0);
	}
	int n;
	cin >> n;
	for(int round=1;round<=n;round++){
		round_update(round);
	}
	cout << *max_element(dp[n], dp[n]+10) << endl;
	return 0;
}
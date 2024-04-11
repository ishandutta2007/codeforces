#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<char>c(N);
	vector<int>num(N);
	for (int i = 0; i < N; i++) {
		cin >> c[i] >> num[i];
	}
	int two[] = { 1,2,4,8,16,32,64,128,256,512 };
	vector<int>bit(10);
	for (int i = 0; i < N; i++) {
		vector<bool>flag(10);
		int bag = 0;
		int box = num[i];
		while(box) {
			if (box % 2) {
				flag[bag] = true;
			}
			bag++;
			box /= 2;
		}
		if (c[i] == '^') {
			for (int j = 0; j < 10; j++) {
				if (bit[j] == 1&&flag[j]) {
					bit[j] = -1;
				}
				else if (bit[j] == -1&&flag[j]) {
					bit[j] = 1;
				}
				else if(bit[j]==2&&flag[j]) {
					bit[j] = 0;
				}
				else if (bit[j] == 0 && flag[j]) {
					bit[j] = 2;
				}
			}
		}
		else if (c[i] == '&') {
			for (int j = 0; j < 10; j++) {
				if (!flag[j]) {
					bit[j] = -1;
				}
			}
		}
		else {
			for (int j = 0; j < 10; j++) {
				if (flag[j]) {
					bit[j] = 1;
				}
			}
		}
		//for (int j = 0; j < 10; j++) {
		//	cout << bit[j] << " ";
		//}
		//cout << endl;
	}
	vector<pair<char, int>>v;
	for (int i = 0; i < 10; i++) {
		if (bit[i]==1||bit[i]==-1) {
			M += two[i];
		}
	}
	if (M) {
		v.push_back({ '|',M });
	}
	M = 0;
	for (int i = 0; i < 10; i++) {
		if (bit[i]==-1||bit[i]==2) {
			M += two[i];
		}
	}
	if (M) {
		v.push_back({ '^',M });
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	//for (int i = 0; i < 32; i++) {
	//	cout << i << " ";
	//	int a = i;
	//	for (int j = 0; j < N; j++) {
	//		if (c[j] == '^') {
	//			a ^= num[j];
	//		}
	//		else if (c[j] == '|') {
	//			a |= num[j];
	//		}
	//		else {
	//			a &= num[j];
	//		}
	//	}
	//	cout << a << " ";
	//	a = i;
	//	for (int j = 0; j < v.size(); j++) {
	//		if (v[j].first == '^') {
	//			a ^= v[j].second;
	//		}
	//		else if (v[j].first == '|') {
	//			a |= v[j].second;
	//		}
	//		else {
	//			a &= v[j].second;
	//		}
	//	}
	//	cout << a << endl;
	//}
	return 0;
}
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
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;

long long int N, M, K, W, H, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	long long int num[100000];
	long long int box[100000];
	vector<vector<long long int>>ret;
	bool flag[100000];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		num[i] += MOD;
		flag[i] = true;
		box[i] = num[i] * (MOD*2) + i;
	}
	sort(box, box + N);
	for (int i = 0; i < N; i++) {
	//	cout << i << endl;
	//	cout << box[i];
		if (flag[(int)(box[i] % (MOD*2))]) {
			long long int c = box[i] % (MOD*2);
			//cout << c << endl;
			flag[c] = false;
			vector<long long int>v;
			v.push_back(c);
			//cout << c << endl;
			while (flag[box[c] % (MOD*2)]) {
		//		cout << c << endl;
				flag[box[c] % (MOD*2)]=false;
				c = box[c] % (MOD*2);
				v.push_back(c);
			}
			ret.push_back(v);
		}
	}
	cout << ret.size() << endl;
	for (auto i : ret) {
		cout << i.size() << " ";
		sort(i.begin(), i.end());
		for (int j = 0; j < i.size(); j++) {
			if (j)cout << " ";
			cout << i[j] + 1;
		}
		cout << endl;
	}
	return 0;
}
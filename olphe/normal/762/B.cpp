#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
const long long int MOD = 1000000007;

int a, b, c;
int N;
multiset<long long int> pricea;
multiset<long long int> priceb;
multiset<long long int> both;
char type[55];
int num[2];
int p;
int mouse;
long long int cost;
int j = 0;

int main() {
	cin >> a >> b >> c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p;
		cin >> type;
		if (type[0] == 'U') {
			pricea.insert(p);
		}
		else {
			priceb.insert(p);
		}
	}
	for (auto i = pricea.begin(); i != pricea.end(); ++i) {
		if (j < a) {
			mouse++;
			cost += *i;
		}
		else {
			both.insert(*i);
		}
		j++;
	}
	j = 0;
	for (auto i = priceb.begin(); i != priceb.end(); ++i) {
		if (j < b) {
			mouse++;
			cost += *i;
		}
		else {
			both.insert(*i);
		}
		j++;
	}
	j = 0;
	for (auto i = both.begin(); i != both.end(); ++i) {
		if (j < c) {
			mouse++;
			cost += *i;
		}
		else {
			break;
		}
		j++;
	}
	cout << mouse << " " << cost << endl;
	return 0;
}
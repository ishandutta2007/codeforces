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

list<int>D;
list<int>R;
int N;
char kind[200001];

int main() {
	cin >> N;
	cin >> kind;
	for (int i = 0; kind[i] != NULL; i++) {
		if (kind[i] == 'D') {
			D.push_back(i);
		}
		else {
			R.push_back(i);
		}
	}
	while (!D.empty()&&!R.empty()) {
		if (D.front() < R.front()) {
			D.push_back(D.front() + N);
			D.pop_front();
			R.pop_front();
		}
		else {
			R.push_back(R.front() + N);
			R.pop_front();
			D.pop_front();
		}
	}
	if (D.empty())cout << "R\n";
	else cout << "D\n";
	return 0;
}
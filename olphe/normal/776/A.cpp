#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N;
string na[2] ;
char box[100];
string bag;

int main() {
	cin >> box;
	na[0] = box;
	cin >> box;
	na[1] = box;
	cout << na[0] <<" "<< na[1]<<endl;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> box;
		bag = box;
		if (bag == na[0]) {
			cin >> box;
			na[0] = box;
			cout << na[0] <<" "<< na[1]<<endl;
		}
		else {
			cin >> box;
			na[1] = box;
			cout << na[0] <<" "<< na[1]<<endl;
		}
	}

	return 0;
}
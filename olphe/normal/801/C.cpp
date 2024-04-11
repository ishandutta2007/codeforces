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
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int N;
long long int P;
long long int a[100000], b[100000];
long long int box;
long double l = 0, r = 10000000000;

int main(){
	cin >> N >> P;
	for (int i = 0; i < N; i++)cin >> a[i] >> b[i];
	for (int i = 0; i < N; i++) {
		box += a[i];
	}
	if (box <= P) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < 500; i++) {
	//	cout << l << " " << r << endl;
		long double mid = (l + r) / 2;
		long double life = 0;
		for (int j = 0; j < N; j++) {
			life += max(mid*(long double)a[j] - (long double)b[j], (long double)0) / (long double)P;
		}
	
		if (life > mid)r = mid;
		else l = mid;
		
	}
	cout << setprecision(15) << (r + l) / 2 << endl;
}
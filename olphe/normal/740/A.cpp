#include "iostream"
#include "algorithm"
using namespace std;

long long int  N, A, B, C;
long long int  price[5];

int main() {
	cin >> N >> A >> B >> C;
	price[1] = min({ A,B + C,C + C + C });
	price[2] = min({ A + A,B,C + C });
	price[3] = min({ A + A + A,A + B,C });
	price[4] = 0;
	cout << price[(4 - N % 4)] << "\n";
	return 0;
}
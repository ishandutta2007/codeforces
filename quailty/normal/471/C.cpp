#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long n, kmax, k, time = 0;
	cin >> n;
	kmax = (long long)((sqrt((double)1 + 24 * n) -1) / 6);
	if (n % 3 == 0){
		for (k = 3; k <= kmax; k = k + 3)
			time = time + 1;
	}
	if (n % 3 == 1){
		for (k = 2; k <= kmax; k = k + 3)
			time = time + 1;
	}
	if (n % 3 == 2){
		for (k = 1; k <= kmax; k = k + 3)
			time = time + 1;
	}
	cout << time;
	cout << "\n";
	return 0;
}
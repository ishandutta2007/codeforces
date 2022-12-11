#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 110;


int main( void ) {

	int n, k;
	cin >> n >> k;

	int ans = 0, t = 0;
	for ( int i = 1 ; i <= n ; ++i ) {
		t += i * 5;
		if ( t + k > 240 ) break;
		ans = i;
	}
	cout << ans << endl;
	return 0;
}
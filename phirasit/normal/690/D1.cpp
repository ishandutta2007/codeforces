#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio( false );

	int r, c;
	string str;

	cin >> r >> c;
	for ( int i = 0 ; i < r ; i++ ) {
		cin >> str;
	}

	int ans = 0;
	for ( int i = 0 ; i < c ; i++ ) {
		ans += ( str[i] == 'B' and ( i == 0 or str[i-1] == '.' ) );
	}

	cout << ans << endl;
	
	return 0;
}
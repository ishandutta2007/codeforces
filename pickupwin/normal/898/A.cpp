#include <iostream>
using namespace std;
int N;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	switch(N%10){
		case 0:
			cout << N << endl;
			break;
		case 1:
			cout << N-1 << endl;
			break;
		case 2:
			cout << N-2 << endl;
			break;
		case 3:
			cout << N-3 << endl;
			break;
		case 4:
			cout << N-4 << endl;
			break;
		case 5:
			cout << N-5 << endl;
			break;
		case 6:
			cout << N+4 << endl;
			break;
		case 7:
			cout << N+3 << endl;
			break;
		case 8:
			cout << N+2 << endl;
			break;
		case 9:
			cout << N+1 << endl;
			break;
		default:
			break;
	}
	return 0;
}
/*
5
*/
/*
113
*/
/*
1000000000
*/
/*
5432359
*/
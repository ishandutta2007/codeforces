							/* in the name of Allah */
#include <iostream>
using namespace std;

long long m;
int n, x, y;
int pnt[100010][2];

int main(){
	cin >> n >> m;
	m %= 2 * n;
	cin >> x >> y;
	for(int i = 0; i < n; i++)
		cin >> pnt[i][0] >> pnt[i][1];
	for(int i = 0; i < m; i++){
		x = 2 * pnt[i % n][0] - x;
		y = 2 * pnt[i % n][1] - y;
	}
	cout << x << ' ' << y << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
/*struct point {
	int x;
	int y;
};
//
vector <int> a;
int N;
pair<vector<int>::iterator, vector<int>::iterator> result;
point z;
//
bool cmp( int a, int b ) {
	return a > b;
}*/
//
int main() {
	//cout.precision(1);
	//freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	if ((s.find("1111111")!=-1)||(s.find("0000000")!=-1)) cout << "YES" << endl; else
												cout << "NO" << endl;
	//
	/*cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());//cmp
	result = equal_range( a.begin(), a.end(),  3);
	//reverse(a.begin(), a.end());
	for (int i = 0; i < N; i++) cout << a[i] << " ";
	cout << endl;
	cout << *result.first << " " << *result.second  << endl;
	//
	z.x = 5; z.y = 7;
	cout << z.x << " " << z.y << endl;
	//
	for (char c = 'A'; c <= 'z'; c++)
		if (((c >= 'A')&&(c <= 'Z'))||((c >= 'a')&&(c <= 'z')))
			cout << c << " " <<(int)c << endl;
	//
	cout << ceil(3.8) << endl;
	cout << floor(3.8) << endl;*/

	//
	return 0;
}
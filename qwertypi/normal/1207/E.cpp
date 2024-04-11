#include <iostream>
#include <vector>
#include <utility>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;

typedef long long ll;

bool used[32768];
int main(){
	fill(used, used+32768, 0);
	cout << "? ";
	for(int i=0;i<100;i++){
		cout << i << ' ';
	}
	cout << endl;
	int res;
	cin >> res;
	int front = res / 128 * 128;
	cout << "? ";
	for(int i=1;i<=100;i++){
		cout << i * 128 << ' ';
	}
	cout << endl;
	cin >> res;
	cout << "! " << front + res % 128;
	return 0;
}
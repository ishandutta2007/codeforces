#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int n;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	cout << (1LL << (ll)(n + 1)) - 2 << endl;
}
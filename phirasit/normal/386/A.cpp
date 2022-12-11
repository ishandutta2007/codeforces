#include <iostream>
#include <algorithm>

#define N 1010

using namespace std;

typedef pair<int,int> pii;
pii arr[N];
int n;

int main() {
	int i;
	cin >> n;
	for(i=1;i<=n;i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr+1,arr+n+1);
	cout << arr[n].second << " " << arr[n-1].first << endl;
	return 0;
}
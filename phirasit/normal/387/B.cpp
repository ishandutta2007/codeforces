#include <iostream>

#define N 3010

using namespace std;

int a[N],b[N];
int n,m;

int main() {
	int i,j;
	cin >> n >> m;
	for(i=0;i<n;i++) {
		cin >> a[i];
	}
	for(i=0;i<m;i++) {
		cin >> b[i];
	}
	for(i=j=0;i<n && j<m;j++) {
		if(b[j] >= a[i]) i++;
	}
	cout << n-i << endl;
	return 0;
}
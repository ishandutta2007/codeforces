#include <iostream>
#include <algorithm>

#define N 110
#define A first
#define B second
#define INF (-1u/2)

using namespace std;

typedef pair<int,int> pii;
pii arr[N];
int opt[2*N];
int n;

int main() {
	int i,j,mx = 0,sum = 0;
	cin >> n;
	for(i=0;i<n;i++) {
		cin >> arr[i].A >> arr[i].B;
		mx += arr[i].A;
		sum += arr[i].B;
	}
	for(i=0;i<=mx;i++)
		opt[i] = INF;
	opt[0] = sum;
	for(i=0;i<n;i++) {
		for(j=mx - arr[i].A;j>=0;j--) {
			if(opt[j] - arr[i].B < opt[j + arr[i].A]) {
				opt[j + arr[i].A] = opt[j] - arr[i].B;
			}
		}
	}
	for(i=0;i<=mx;i++) {
		if(i >= opt[i])
			break;
	}
	cout << i << endl;
	return 0;
}
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define pii pair<int,int>

using namespace std;
int n,m,a,b,c;
char aa[1000];
int arr[2][1000005];

int main() {
	scanf("%d %d",&n,&m);
	scanf("%d %d",&a,&b);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[0][i]);
	}
	for (int j=0;j<m;j++) {
		scanf("%d",&arr[1][j]);
	}
	sort(arr[0],arr[0]+n);
	sort(arr[1],arr[1]+m);
	if (arr[0][a-1] < arr[1][m-1-(b-1)]) {
		cout << "YES" <<endl;
	}else {
		cout << "NO" <<endl;
	}
}
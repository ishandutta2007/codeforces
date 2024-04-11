#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int n, b[111][111];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    scanf("%d", &b[i][j]);
	}
    }
    for (int i=0; i<n; i++) {
	int a=0;
	for (int j=0; j<n; j++) {
	    if (i==j) continue;
	    a|=b[i][j];
	}
	printf("%d%c", a, i==n-1?'\n':' ');
    }

    return 0;
}
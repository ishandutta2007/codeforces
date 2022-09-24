#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string s;
int q, n;
int f[5001][5001];
int main() {
    cin>>s;
    n=s.size();
    for (int i=0; i<n; i++) {
	for (int j=0; i+j<n && 0<=i-j; j++) {
	    if (s[i+j]==s[i-j]) f[i-j][i+j]++;
	    else break;
	}
    }
    for (int i=0; i<n-1; i++) {
	for (int j=0; i+1+j<n && 0<=i-j; j++) {
	    if (s[i+1+j]==s[i-j]) {
		f[i-j][i+1+j]++;
	    } else {
		break;
	    }
	}
    }
    for (int i=1; i<n; i++) {
	for (int j=0; j<n-i; j++) {
	    f[j][i+j]+=f[j][i+j-1]+f[j+1][i+j]-f[j+1][i+j-1];
	}
    }
    scanf("%d", &q);
    for (;q--;) {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d\n", f[x-1][y-1]);
    }
    return 0;
}
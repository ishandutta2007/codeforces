#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string s;
int m;
int sums[100010];
int main() {
    cin>>s;
    for (int i=1; i<int(s.size()); i++) {
	if (s[i-1]==s[i]) sums[i]++;
	sums[i]+=sums[i-1];
    }
    scanf("%d", &m);
    for (;m--;) {
	int r, l; scanf("%d%d", &l, &r); l--; r--;
	printf("%d\n", sums[r]-sums[l]);
    }
    return 0;
}
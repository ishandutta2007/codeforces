#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


typedef long long LL;

int n, a[100010];
set<int> se;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);

    for (int i=0; i<n; i++) {
	se.insert(a[i]);
	int s=0;
	for (int j=i-1; j>=0; j--) {
	    s|=a[j];
	    if ((a[i]&~s)==0) break;
	    se.insert(s|a[i]);
	}
    }
    printf("%d\n", se.size());

    return 0;
}
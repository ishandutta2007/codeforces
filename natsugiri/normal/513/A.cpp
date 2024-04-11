#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;


int A, B, C, D;
int main() {
    scanf("%d%d%d%d", &A, &B, &C, &D);
    for (;;) {
	if (A == 0) {
	    puts("Second");;
	    break;
	}
	A--;
	if (B == 0) {
	    puts("First");
	    break;
	}
	B--;
    }
    return 0;
}

#include<iostream>
#include<cstdio>

#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld)-1);
const int inf = (int) 1.01e9;
const ld eps = 1e-12;

#define sz(a) (int) (a).size()

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif
#define MAX 1002


int a[2002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int countt = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] < a[j]) {
				countt++;
			}
		}
		countt++;
		if (i) {
			printf(" ");
		}
		printf("%d", countt);
	}
	puts("");
	return 0;
}
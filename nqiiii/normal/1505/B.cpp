#include <bits/stdc++.h>
using namespace std;
int x, v;
int main() {
	scanf("%d", &x);
	printf("%d", x % 9 ? x % 9 : 9);
}
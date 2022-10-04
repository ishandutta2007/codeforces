#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>

using namespace std;

char buf[10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", buf);
	int hh = buf[0] * 10 + buf[1] - 11*'0';
	int mm = buf[3] * 10 + buf[4] - 11*'0';
	int a;
	scanf("%d", &a);
	mm = mm + a;
	int q = mm / 60;
	mm = mm % 60;
	hh += q;
	hh = hh % 24;
	printf("%02d:%02d", hh, mm);
}
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int l = -1, r = 5000000, mid;
int man[500000];
int food[500000];
char s[500000];
int totm = 0;
int totf = 0;
int n;

//int curm, curf

int MAX(int a, int b){return a>b?a:b;}

bool check(int t) {
int curm=1, curf=1;

while (curm <= totm && curf <= totf) {
	//printf("man@%d. food@%d.  \n", man[curm], food[curf]);

	int leftmost=food[curf], rightmost = 0;
	
	int man_pos = man[curm];

	if (leftmost < man_pos) {
		int Time = t;
		curf++;
		Time -= (man_pos-leftmost);
		if (Time < 0)
		 	return 0;

		rightmost = MAX(MAX(man_pos, leftmost+Time), man_pos + (Time/2));
		while (food[curf] <= rightmost && curf <= totf)
			curf++;


	}
	else {
		rightmost = man_pos + t;
		while (food[curf] <= rightmost && curf <= totf)
			curf++;

	}

	curm++;
}

	if (curf > totf) return 1;
	else return 0;
}

int main () {
	scanf("%d", &n);
	scanf("%s", s+1);
	for (int i=1; i<=n; i++) {
		if (s[i] == '.') continue;
		if (s[i] == '*') {
			food[++totf] = i;
		}
		if (s[i] == 'P') {
			man[++totm] = i;
		}
	}

	while ( l+1 < r) {
		//printf("before l %d. mid %d. r %d.\n", l, mid, r);
		if ( check(mid = (l+r)/2) )
			r = mid;
		else
			l = mid;
		//printf("after  l %d. mid %d. r %d.\n", l, mid, r);
	}

	//printf("check2 == %d\n", check(2));

	printf("%d\n", r);

	return 0;
}
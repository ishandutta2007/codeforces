#include <cstdio>
#include <cstring>

const int N = 500000;

int n;
int p[N];
char s[N + 5];

int main () {
	scanf ("%d", &n);
	for (int i=0; i<n; i++) scanf ("%d", p + i);
	getchar (); gets (s);
	
	int len = strlen (s);
	long long maks = 0;
	for (int i=0; i<len; i++) 
		if (s[i] == 'B') maks += p[i];
	
	long long tmp = maks;
	long long tmp2 = maks;
	for (int i=0; i<len; i++) {
		if (s[i] == 'A') tmp += p[i];
		else tmp -= p[i];
		
		maks = (tmp < maks ? maks : tmp);
	}
		
	for (int i=len-1; i>=0; i--) {
		if (s[i] == 'A') tmp2 += p[i];
		else tmp2 -= p[i];
		
		maks = (tmp2 < maks ? maks : tmp2);
	}
	
	printf ("%I64d\n", maks);
	
	return 0;
}
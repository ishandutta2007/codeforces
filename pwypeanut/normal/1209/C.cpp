#include <bits/stdc++.h>
using namespace std;

int TC;
int assm[200005];
char S[200005];

int main() {
	scanf("%d", &TC);
	while (TC--) {
		int N;
		 scanf("%d%s", &N, &S);
		 bool found = 0;
		 for (int d = 0; d <= 9; d++) {
			 int laste = -1;
			 for (int i = 0; i < N; i++) if (S[i] < char('0' + d)) laste = max(laste, i);
			 for (int i = 0; i < N; i++) {
				 if (S[i] < char('0' + d) || (S[i] == char('0' + d) && i > laste)) assm[i] = 1;
				 else assm[i] = 2;
			 }
			 string a = "", b = "";
			 for (int i = 0; i < N; i++) {
				 if (assm[i] == 1) a += S[i];
				 else b += S[i];
			 }
			 bool fail = 0;
			 for (int i = 0; i < (int)a.length() - 1; i++) if (a[i] > a[i + 1]) fail = 1;
			 for (int i = 0; i < (int)b.length() - 1; i++) if (b[i] > b[i + 1]) fail = 1;
			 if (!fail) {
				 found = 1;
				 for (int i = 0; i < N; i++) printf("%d",assm[i]);
				 printf("\n");
				 break;
			 }
		 }
		 if (!found) printf("-\n");
	}
}
#pragma gcc optmize("Ofast")
#include <bits/stdc++.h>

long long XX, XY, YX, YY;
int bits[100005];
int n;

int readbit() {
    char ch = getchar();
    while(ch != '0' && ch != '1') ch = getchar();
    return ch - '0';
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) bits[i] = readbit();
    for (int i = 0; i < n; ++i) {
        int x = readbit();
        if (x == 0 && bits[i] == 0) ++YY;
		else if(x == 1 && bits[i] == 0) ++YX;
		else if(x ==1 && bits[i] == 1) ++XX;
		else ++XY;
    }
	printf("%lld", XX * YY + XY * YX + XY * YY);
	return 0;
}
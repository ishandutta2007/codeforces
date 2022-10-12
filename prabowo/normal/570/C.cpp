#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[300002];

int main() {
    scanf("%d %d\n", &n, &m);
    gets(s);

    int now = 0;
    for (int i=1; i<n; i++) now += (s[i] == '.' && s[i-1] == '.');

    int x;
    char c;
    for (int i=0; i<m; i++) {
    	scanf("%d %c\n", &x, &c);
    	x--;
    	if (c == '.' && s[x] != '.') {
    		now += (x > 0   && s[x-1] == '.');
    		now += (x < n-1 && s[x+1] == '.');
    		s[x] = '.';
    	} else if (c != '.' && s[x] == '.'){
    		now -= (x > 0   && s[x-1] == '.');
    		now -= (x < n-1 && s[x+1] == '.');
    		s[x] = c;
    	}

    	printf("%d\n", now);
    }
	return 0;
}
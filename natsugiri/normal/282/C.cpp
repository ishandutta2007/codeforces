#include<cstdio>
#include<cstring>

char a[1000010], b[1000010];
int m, n;
int main() {
    scanf("%s%s", a, b);
    m=strlen(a); n=strlen(b);

    if (m!=n) {
	puts("NO");
	return 0;
    }

    int p=0, q=0;
    for (int i=0; i<n; i++) {
	if (a[i]=='1') p=1;
	if (b[i]=='1') q=1;
    }
    puts(p==q?"YES":"NO");
	    
    return 0;
}
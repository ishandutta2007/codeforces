#include <cstdio>
using namespace std;
int i,j,n,m,r;
char s[110][110],c;
bool a[256];
int main() {
	scanf("%d %d %c",&n,&m,&c); gets(s[0]);
	for (i=0; i<n; i++) gets(s[i]);
	for (i=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]!=c) {
		if (i>0 && s[i-1][j]==c) a[s[i][j]]=true;
		if (j>0 && s[i][j-1]==c) a[s[i][j]]=true;
		if (i<n-1 && s[i+1][j]==c) a[s[i][j]]=true;
		if (j<m-1 && s[i][j+1]==c) a[s[i][j]]=true;
	}
	for (i='A', r=0; i<='Z'; i++) if (a[i]) r++;
	printf("%d\n",r);
	return 0;
}
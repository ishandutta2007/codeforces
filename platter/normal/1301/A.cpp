#include <cstdio>
#include <cstring>
using namespace std;

char a[101];
char b[101];
char c[101];

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		scanf("%s\n",a);
		scanf("%s\n",b);
		scanf("%s\n",c);
		int n=strlen(a);
		bool flag=true;
		for(int i=0;i<n;i++) {
			if (a[i]!=c[i]&&b[i]!=c[i]) {
				flag=false;
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
}
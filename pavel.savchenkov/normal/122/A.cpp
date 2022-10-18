#include <cstdio>

using namespace std;

bool ok(int a) {
	while (a>0) 
		if (a%10!=4&a%10!=7) return false; else a/=10;
	return true;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		if (ok(i)&n%i==0) {printf("YES");return 0;}
	printf("NO");
	return 0;
}
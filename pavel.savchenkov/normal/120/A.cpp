#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char s[20];
	scanf("%s",&s);
	int k;
	scanf("%d",&k);
	if ((strcmp("front",s)==0&k==1)|(strcmp("back",s)==0&k==2)) printf("L"); else printf("R");
	return 0;
}
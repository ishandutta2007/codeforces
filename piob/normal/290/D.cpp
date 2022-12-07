#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

int n, k;
char buff[53];

int main(){
	scanf("%s", buff);
	n = strlen(buff);
	scanf("%d", &k);
	FWD(i,0,n){
		buff[i] = tolower(buff[i]);
		if(buff[i]-'a' < k)
			buff[i] = toupper(buff[i]);
	}
	printf("%s\n", buff);
	return 0;
}
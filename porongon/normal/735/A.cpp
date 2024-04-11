#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define fore(i,a,n) for(int i = a,qwer=n;i<qwer;i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 100500;
char c[105];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",c);
	int p;
	fore(i,0,n)
		if(c[i] == 'G')
			p = i;
	bool f = 0;
	for(int i = p;i< n;i+=k)
		if(c[i] == '#')
			break;
		else if(c[i] == 'T')
			f = 1;
	for(int i = p; i >= 0;i-=k)
		if(c[i] == '#')
			break;
		else if(c[i] == 'T')
			f = 1;
	if(f)
		puts("YES");
	else
		puts("NO");
}
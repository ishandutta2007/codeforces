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
vector<int> ans;
int main() {
	int n;
	scanf("%d",&n);
	bool f = 1;
	for(int i = 2;i*i<=n;i++)
		if(n % i == 0)
			f = 0;
	if(f)
		puts("1");
	else if(n %2 == 0)
		puts("2");
	else {
		n -= 2;
		f = 1;
		for(int i = 2;i*i<=n;i++)
			if(n % i == 0)
				f = 0;
		if(f)
			puts("2");
		else
			puts("3");
	}
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
int a[MAXN];

int main(){
	std::set<int> S;
	FOR(i,1,6) scanf("%d",a+i);
	std::sort(a+1,a+6+1);
	if(a[1] != a[4] && a[2] != a[5] && a[3] != a[6]){
		puts("Alien");
		return 0;
	}
	if((a[1]==a[4]&&a[5]==a[6])) puts("Elephant");
	else if((a[2] == a[5]) &&a[1]==a[6])puts("Elephant");
	else if(a[3]==a[6]&&a[1]==a[2])puts("Elephant");
	else puts("Bear");
	return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
char ch[23];
std::multiset<std::string> S;
std::string str,ans;
int del[MAXN],tt[MAXN];
std::vector<std::string> SS;
int f[MAXN][26];

inline bool cmp(std::string a,std::string b){
	return a.length() < b.length();
}

int main(){
	int n;scanf("%d",&n);
	if(n <= 3){
		FOR(i,1,n){
			printf("? %d %d\n",i,i);std::fflush(stdout);
			scanf("%s",ch+1);
			ans = ans+ch[1];
		}
		ans = "! " + ans;
		std::cout << ans << std::endl;std::fflush(stdout);
		return 0;
	}
	// solve(1,n/2)
	printf("? 1 %d\n",n/2);std::fflush(stdout);
	FOR(i,1,(n/2)*(n/2+1)/2){
		std::cin >> str;std::sort(all(str));S.insert(str);
	}
	printf("? 1 %d\n",n/2-1);std::fflush(stdout);
	FOR(i,1,(n/2-1)*(n/2)/2){
		std::cin >> str;std::sort(all(str));S.erase(S.find(str));
	}
	for(auto x:S) SS.pb(x);
	std::sort(all(SS),cmp);
	for(auto x:SS){
		FOR(i,0,25) tt[i] = del[i];
		char t;
		FOR(i,0,(int)x.length()-1){
			if(!tt[x[i]-'a']) t = x[i];
			tt[x[i]-'a']--;
		}
		del[t-'a']++;
		ans = t+ans;
	}
	// std::cout << ans << std::endl;
	printf("? %d %d\n",1,n);std::fflush(stdout);
	FOR(i,1,n*(n+1)/2){
		std::cin >> str;
		FOR(i,0,(int)str.length()-1) f[str.length()][str[i]-'a']++;
	}
	ROF(i,n,1){
		int l = i,r = n-i+1;
		// DEBUG(l);DEBUG(r);
		if(l > r) continue;
		FOR(x,0,25){
			int t = f[i][x]-f[i-1][x];
			FOR(i,l,r-1) if(ans[i-1]-'a' == x) t--;
			if(t) {ans = ans+(char)(x+'a');break;}
		}
	}
	ans = "! " + ans;
	std::cout << ans;std::fflush(stdout);
	return 0;
}
//rnnnqnnrn
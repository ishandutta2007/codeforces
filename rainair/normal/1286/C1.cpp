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

std::multiset<std::string> S;
std::string str,ans;
int del[MAXN],tt[MAXN];
std::vector<std::string> SS;

inline bool cmp(std::string a,std::string b){
	return a.length() < b.length();
}

int main(){
	int n;std::cin >> n;
	std::cout << "? 1 " << n << std::endl;
	std::cout.flush();
	FOR(i,1,n*(n+1)/2){
		std::cin >> str;
		std::sort(all(str));
		S.insert(str);
	}
	if(n == 1){
		std::cout << "! " << str << std::endl;
		std::cout.flush();
		return 0;
	}
	std::cout << "? 1 " << n-1 << std::endl;
	std::cout.flush();
	FOR(i,1,(n-1)*n/2){
		std::cin >> str;
		std::sort(all(str));
		S.erase(S.find(str));
	}
	for(auto x:S) SS.pb(x);
	std::sort(all(SS),cmp);
	for(auto str:SS){
		FOR(i,0,25) tt[i] = del[i];
		char t;
		// std::cout << str << std::endl;
		FOR(i,0,(int)str.length()-1){
			if(!tt[str[i]-'a']) t = str[i];
			tt[str[i]-'a']--;
		}
		del[t-'a']++;
		ans = t+ans;
	}
	ans = "! " + ans;
	std::cout << ans << std::endl;
	std::cout.flush();
	return 0;
}
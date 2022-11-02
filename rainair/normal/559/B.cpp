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

const int MAXN = 2e5 + 5;
std::string a,b;
int n;

inline std::string work(std::string str){
	int t = str.length();
	if(t&1) return str;
	std::string s1 = work(str.substr(0,t/2));
	std::string s2 = work(str.substr(t/2));
	// DEBUG(s1);DEBUG(s2);
	if(s1 > s2) std::swap(s1,s2);
	return s1+s2;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> a >> b;
	puts(work(a) == work(b) ? "YES" : "NO");
	return 0;
}
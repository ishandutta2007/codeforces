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

const int MAXN = 1e5 + 5;
std::string str;
int n;
int f[MAXN][2];

int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> str;int n = str.length();
	if(n <= 5){
		puts("0");return 0;
	}
	f[n+1][0] = f[n+1][1] = 1;
	ROF(i,n,6){
		FOR(j,0,1){
			if(j == 0){
				f[i][j] |= (f[i+2][0]&(!(str[i-1]==str[i+2-1]&&str[i+1-1]==str[i+3-1])))|(f[i+2][1]);
			}
			else{
				f[i][j] |= (f[i+3][0])|(f[i+3][1]&(!(str[i-1]==str[i+3-1]&&str[i+1-1]==str[i+4-1]&&str[i+2-1]==str[i+5-1])));
			}
		}
	}
	std::set<std::string> S;
	FOR(i,6,n){
		if(f[i][0]) S.insert(str.substr(i-1,2));
		if(f[i][1]) S.insert(str.substr(i-1,3));
	}
	std::cout << S.size() << '\n';
	for(auto x:S) std::cout << x << '\n';
	return 0;
}
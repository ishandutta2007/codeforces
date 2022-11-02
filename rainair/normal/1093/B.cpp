#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl


int main(){
	int T;scanf("%d",&T);
	while(T--){
		std::string str;
		std::cin >> str;
		std::sort(str.begin(),str.end());
		if(str[0] == str[str.size()-1]){
			puts("-1");continue;
		}
		std::cout << str << std::endl;
	}

	return 0;
}
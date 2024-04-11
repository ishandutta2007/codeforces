#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

std::pair<std::string,int> t[3];

int main(){
	int n;scanf("%d",&n);
	std::cin >> t[1].first;
	t[1].second++;
	for(int i = 1;i < n;i++){
		std::string str;
		std::cin >> str;
		if(str != t[1].first){
			t[2].first = str;
			t[2].second++;
		}
		else
			t[1].second++;
	}
	std::cout << ((t[1].second > t[2].second) ? t[1].first : t[2].first);
	//getchar();getchar();
	return 0;
}
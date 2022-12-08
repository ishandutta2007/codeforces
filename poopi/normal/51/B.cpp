										/* in the name of Allah */
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int cnt[5010];
vector <int> v;

int main(){
	string str = "", tmp;
	while(cin >> tmp)
		str += tmp;
	for(int i = 0; i < str.length(); i++)
		if(str[i] == '>' || str[i] == '<')
			str[i] = ' ';
	istringstream sin(str);
	int pnt = 0;
	while(sin >> tmp){
		if(tmp == "table")
			v.push_back(pnt++);
		if(tmp == "/table")
			v.pop_back();
		if(tmp == "td")
			cnt[v.back()]++;
	}
	sort(cnt, cnt + pnt);
	for(int i = 0; i < pnt; i++){
		if(i > 0) cout << ' ';
		cout << cnt[i];
	}
	cout << endl;
	return 0;
}
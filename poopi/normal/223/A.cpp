										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, char>

int n;
char s[100010];
bool ok[100010];
vector <P> v;

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++){
		if(s[i] == '(' || s[i] == '[')
			v.push_back(P(i, s[i]));
		else if(v.empty()) continue;
		else if((s[i] == ')' && v.back().second == '(') || (s[i] == ']' && v.back().second == '[')){
			ok[i] = ok[v.back().first] = true;
			v.pop_back();
		}
		else v.clear();
	}
	int str = 0, end = -1, cnt = 0;
	int mx = 0, idx = n;
	while(end + 1 < n){
		end++;
		if(!ok[end]){
			str = end + 1;
			cnt = 0;
		}
		else{
			if(s[end] == '[')
				cnt++;
			if(cnt > mx){
				mx = cnt;
				idx = str;
			}
		}
	}
	cout << mx << endl;
	while(idx < n && ok[idx]) cout << s[idx++];
	cout << endl;
	return 0;
}
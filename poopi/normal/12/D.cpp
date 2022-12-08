										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

struct tri{
	int x;
	P v;
	tri(){}
	bool operator < (const tri &oth) const{
		if(x != oth.x)
			return x < oth.x;
		return v < oth.v;
	}
};

int n;
tri arr[500010];
set <P> st;

bool isBad(P val){
	set <P>::iterator it = st.upper_bound(val);
	if(it != st.end() && (*it).first == val.first)
		it++;
	if(it == st.end())
		return false;
	return (*it).second > val.second;
}

void insert(P val){
	set <P>::iterator it = st.lower_bound(val);
	if(it != st.end() && (*it).second >= val.second)
		return;
	while(it != st.begin() && (*--it).first <= val.first && (*it).second <= val.second)
		it = st.erase(it);
	st.insert(val);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i].x);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i].v.first);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i].v.second);
	sort(arr, arr + n);
	reverse(arr, arr + n);
	int cnt = 0, p = 0;
	for(int i = 0; i < n; i++){
		if(i != n - 1 && arr[i].x == arr[i + 1].x)
			continue;
		for(int j = p; j <= i; j++)
			if(isBad(arr[j].v))
				cnt++;
		for(int j = p ; j <= i; j++)
			insert(arr[j].v);
		p = i + 1;
	}
	cout << cnt << endl;
	return 0;
}
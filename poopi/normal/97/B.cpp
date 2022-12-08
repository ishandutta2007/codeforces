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
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
P arr[10010];
set <P> st;

void rec(int str, int end){
	if(str == end)
		return;
	int mid = (str + end) / 2;
	rec(str, mid);
	rec(mid + 1, end);
	for(int i = str; i <= end; i++)
		st.insert(P(arr[mid].first, arr[i].second));
}

int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> arr[i].first >> arr[i].second;
			st.insert(arr[i]);
		}
		sort(arr, arr + n);
		rec(0, n - 1);
		cout << st.size() << endl;
		for(set <P> ::iterator it = st.begin(); it != st.end(); it++){
			P tmp = *it;
			cout << tmp.first << ' ' << tmp.second << endl;
		}
	}
	return 0;
}
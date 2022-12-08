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
#define P pair<int, int>

struct tri{
	int64 ct;
	int idx, st;
	tri(int64 c, int s, int i){
		ct = c, st = s, idx = i;
	}
	bool operator < (const tri &a) const{
		if(ct != a.ct)
			return ct < a.ct;
		return st < a.st;
	}
};

int k, n;
vector <P> st, pc;
vector <int> res[1010];

int main(){
	while(cin >> n >> k){
		int a, b;
		int64 sum = 0;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			if(b == 1)
				st.push_back(P(a, i));
			else pc.push_back(P(a, i));
			sum += 2 * a;
		}
		sort(st.begin(), st.end());
		reverse(st.begin(), st.end());
		sort(pc.begin(), pc.end());
		reverse(pc.begin(), pc.end());
		if(st.size() >= k){
			for(int i = 0; i < k - 1; i++){
				res[i].push_back(st[i].second);
				sum -= st[i].first;
			}
			if(!pc.empty() && pc.back().first < st.back().first)
				sum -= pc.back().first;
			else sum -= st.back().first;
			for(int i = k - 1; i < st.size(); i++)
				res[k - 1].push_back(st[i].second);
			for(int i = 0; i < pc.size(); i++)
				res[k - 1].push_back(pc[i].second);
		}
		else{
			for(int i = 0; i < st.size(); i++){
				res[i].push_back(st[i].second);
				sum -= st[i].first;
			}
			int rem = k - st.size();
			for(int i = 0; i < rem - 1; i++)
				res[st.size() + i].push_back(pc[i].second);
			for(int i = rem - 1; i < pc.size(); i++)
				res[k - 1].push_back(pc[i].second);
		}
		cout.precision(1);
		cout.setf(ios::fixed | ios::showpoint);
		cout << (double)sum / 2. << endl;
		for(int i = 0; i < k; i++){
			cout << res[i].size();
			for(int j = 0; j < res[i].size(); j++)
				cout << ' ' << res[i][j] + 1;
			cout << endl;
		}
	}
	return 0;
}
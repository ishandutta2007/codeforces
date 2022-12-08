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

int n, m, k;
int cx, cy;
int res = 0;
map <int, int> mpx, mpy;
int revx[100010], revy[100010];
vector <P> x[100010], y[100010];
vector <P> poss;

int main(){
	cin >> n >> m >> k;
	int a, b, c, d;
	for(int i = 0; i < k; i++){
		cin >> a >> b >> c >> d;
		if(a == c){
			if(mpx.find(a) == mpx.end()){
				revx[cx] = a;
				mpx[a] = cx++;
			}
			x[mpx[a]].push_back(P(max(b, d), -1));
			x[mpx[a]].push_back(P(min(b, d), 1));
		}
		else{
			if(mpy.find(b) == mpy.end()){
				revy[cy] = b;
				mpy[b] = cy++;
			}
			y[mpy[b]].push_back(P(max(a, c), -1));
			y[mpy[b]].push_back(P(min(a, c), 1));
		}
	}
	if((n - cx - 1) % 2){
		int t = 1;
		while(mpx.find(t) != mpx.end())
			t++;
		revx[cx] = t;
		mpx[t] = cx++;
	}
	int res = 0;
	if((m - cy - 1) % 2){
		int t = 1;
		while(mpy.find(t) != mpy.end())
			t++;
		revy[cy] = t;
		mpy[t] = cy++;
	}
	for(int i = 0; i < cx; i++){
		sort(x[i].begin(), x[i].end());
		int rem = m, cnt = 0;
		for(int j = 0; j < x[i].size(); j++){
			if(cnt > 0)
				rem -= x[i][j].first - x[i][j - 1].first;
			cnt += x[i][j].second;
		}
		poss.push_back(P(rem, i));
		res ^= rem;
	}
	for(int i = 0; i < cy; i++){
		sort(y[i].begin(), y[i].end());
		int rem = n, cnt = 0;
		for(int j = 0; j < y[i].size(); j++){
			if(cnt > 0)
				rem -= y[i][j].first - y[i][j - 1].first;
			cnt += y[i][j].second;
		}
		poss.push_back(P(rem, -i - 1));
		res ^= rem;
	}
	if(res){
		cout << "FIRST" << endl;
		int gd;
		for(int i = 0; i < poss.size(); i++)
			if((poss[i].first ^ res) < poss[i].first)
				gd = i;
		int idx = poss[gd].second;
		vector <P> v;
		if(idx >= 0)
			v = x[idx];
		else v = y[-idx - 1];
		v.push_back(P(max(n, m), 2));
		sort(v.begin(), v.end());
		int sum = v[0].first, cnt = 1;
		int p = 1, nd = poss[gd].first - (poss[gd].first ^ res);
		for(; sum < nd && p < v.size(); p++){
			if(cnt == 0)
				sum += v[p].first - v[p - 1].first;
			cnt += v[p].second;
		}
		if(idx >= 0)
			cout << revx[idx] << " 0 " << revx[idx] << ' ' << v[p - 1].first - (sum - nd) << endl;
		else cout << "0 " << revy[-idx - 1] << ' ' << v[p - 1].first - (sum - nd) << ' ' << revy[-idx - 1] << endl;
	}
	else cout << "SECOND" << endl;
	return 0;
}
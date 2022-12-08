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
#define Max 255

struct node{
	vector <int> v;
	node(vector <int> _v){
		v = _v;
	}
	bool operator < (const node &a) const{ 
		return v.size() > a.v.size();
	}
};

int rem = 255;
int n, len[300];
vector <int> need[300];
int st[300][3];
priority_queue < node > q;
bool mark[260];
vector <int> v, tmp;

void setSt(int x, int fir, int sec, int K){
	for(int i = 0; i < v.size(); i++)
		if(x == v[i])
			return;
	if(x > 0 && x <= Max){
		tmp = v;
		tmp.push_back(x);
		if(len[x] == -1 || len[x] >= tmp.size() - 1)
			q.push(node(tmp));
		if(len[x] == -1 || len[x] > tmp.size()){
			if(len[x] == -1)
				rem--;
			len[x] = tmp.size() - 1;
			need[x] = tmp;
			st[x][0] = fir;
			st[x][1] = sec;
			st[x][2] = K;
		}
	}
}

string reg(int x){
	string ret = "eax";
	ret[1] += x;
	return ret;
}

int main(){
	memset(len, -1, sizeof len);
	len[1] = 0;
	v.push_back(1);
	need[1] = v;
	q.push(node(v));
	while(rem > 1 && !q.empty()){
		v = q.top().v;
		q.pop();
		for(int i = 0; i < v.size(); i++){
			for(int j = 1; j <= 8; j *= 2){
				setSt(v[i] * j, -1, v[i], j);
				for(int k = 0; k < v.size(); k++)
					setSt(v[k] + v[i] * j, v[k], v[i], j);
			}
		}
	}
	st[254][0] = 127;
	st[254][1] = 127;
	st[254][2] = 1;
	need[254].clear();
	need[254].push_back(1);
	need[254].push_back(5);
	need[254].push_back(13);
	need[254].push_back(23);
	need[254].push_back(127);
	need[254].push_back(254);
	while(cin >> n){
		cout << (int)need[n].size() - 1 << endl;
		for(int i = 1; i < need[n].size(); i++){
			int r1, r2, x = need[n][i], K;
			for(int j = 0; j < i; j++){
				for(int k = 1; k <= 8; k *= 2){
					if(need[n][j] * k == x){
						r1 = -1;
						r2 = j;
						K = k;
					}
					for(int j2 = 0; j2 < i; j2++){
						if(need[n][j2] + need[n][j] * k == x){
							r1 = j2;
							r2 = j;
							K = k;
						}
					}
				}
			}
			if(r1 == -1)
				cout << "lea " << reg(i) << ", [" << K << "*" << reg(r2) << "]" << endl;
			else cout << "lea " << reg(i) << ", [" << reg(r1) << " + " << K << "*" << reg(r2) << "]" << endl;
		}
	}
	return 0;
}
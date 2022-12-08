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

struct triple{
	string name;
	int64 w, h;
	triple(){}
	triple(string n, int64 ww, int64 hh){
		name = n, w = ww, h = hh;
	}
	bool operator < (const triple &a) const{
		return name < a.name;
	}
};

int n, T;
string name[110];
map <string, int64> mp;
int64 type[110], br[110];
int64 sp[110];
int64 deg[110], cnt[110];
int64 mat[110][110];
int64 w[110], h[110];
queue <int64> q;
triple arr[110];
bool hv[110];

int main(){
	string s1, s2, s3, s4;
	int a, b;
	while(cin >> T){
		while(!q.empty())
			q.pop();
		n = 0;
		memset(cnt, 0, sizeof cnt);
		memset(mat, 0, sizeof mat);
		memset(deg, 0, sizeof deg);
		memset(br, 0, sizeof br);
		memset(sp, 0, sizeof sp);
		memset(w, 0, sizeof w);
		memset(h, 0, sizeof h);
		for(int i = 0; i < T; i++){
			cin >> s1;
			if(s1[0] == 'W'){
				cin >> s1;
				for(int i = 0; i < s1.length(); i++)
					if(s1[i] == '(' || s1[i] == ')' || s1[i] == ',')
						s1[i] = ' ';
				istringstream sin (s1);
				sin >> s2 >> a >> b;
				if(mp.find(s2) == mp.end()){
					name[n] = s2;
					mp[s2] = n++;
				}
				type[mp[s2]] = 0;
				w[mp[s2]] = a;
				h[mp[s2]] = b;
			}
			else if(s1[0] == 'H'){
				cin >> s2;
				if(mp.find(s2) == mp.end()){
					name[n] = s2;
					mp[s2] = n++;
				}
				type[mp[s2]] = 1;
			}
			else if(s1[0] == 'V'){
				cin >> s2;
				if(mp.find(s2) == mp.end()){
					name[n] = s2;
					mp[s2] = n++;
				}
				type[mp[s2]] = 2;
			}
			else{
				for(int i = 0; i < s1.length(); i++)
					if(s1[i] == '(' || s1[i] == ')' || s1[i] == '.')
						s1[i] = ' ';
				istringstream sin (s1);
				sin >> s2 >> s3;
				if(s3[0] == 'p'){
					sin >> s4;
					mat[mp[s2]][mp[s4]]++;
					deg[mp[s2]]++;
					cnt[mp[s2]]++;
				}
				else{
					sin >> a;
					if(s3[4] == 'b')
						br[mp[s2]] = a;
					else sp[mp[s2]] = a;
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(deg[i] == 0)
				q.push(i);
		}
		while(!q.empty()){
			int64 t = q.front();
			q.pop();
			if(type[t] != 0 && cnt[t] != 0){
				w[t] += 2 * br[t];
				h[t] += 2 * br[t];
				if(type[t] == 1)
					w[t] += (cnt[t] - 1) * sp[t];
				else h[t] += (cnt[t] - 1) * sp[t];
			}
			for(int i = 0; i < n; i++){
				if(mat[i][t] > 0){
					int pt = i;
					int tot = mat[i][t];
					deg[pt] -= tot;
					if(type[pt] == 1){
						w[pt] += tot * w[t];
						h[pt] = max(h[pt], h[t]);
					}
					else{
						h[pt] += tot * h[t];
						w[pt] = max(w[pt], w[t]);
					}
					if(deg[pt] == 0)
						q.push(pt);
				}
			}
		}
		for(int i = 0; i < n; i++){
			arr[i] = triple(name[i], w[i], h[i]);
		}
		sort(arr, arr + n);
		for(int i = 0; i < n; i++)
			cout << arr[i].name << ' ' << arr[i].w << ' ' << arr[i].h << endl;
	}
	return 0;
}
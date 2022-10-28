#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 3e6 + 6;
int n;
int arr[N][30];
int siz[N];
char tmp[N];
int len;
vector < pair < int , pair < int , int > > > v[26];
vector < pair < int , int > > g[N];
int val[N];
int head[N];
int ans[M];
map < string , int > mp;
int cur;
void dfs(int x){
	cur = max(cur , val[x] + siz[x] - 1);
	for(auto y : g[x]){
		if(val[y.first]){
			continue;
		}
		val[y.first] = val[x] + y.second;
		cur = max(cur , val[y.first] + siz[y.first] - 1);
		dfs(y.first);
	}
}
int main(){
	scanf("%d" , &n);
	mp.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , tmp + 1);
		len = strlen(tmp + 1);
		int mask = 0;
		bool rip = 0;
		for(int j = 1 ; j <= len ; ++j){
			int val = tmp[j] - 'a';
			if((mask >> val) & 1){
				rip = 1;
				break;
			}
			mask |= 1 << val;
		}
		if(rip){
			printf("NO\n");
			return 0;
		}
		mp[tmp + 1] = 0;
		for(int j = 1 ; j <= len ; ++j){
			arr[i][j] = tmp[j] - 'a';
			v[arr[i][j]].emplace_back(make_pair(j , make_pair(len , i)));
		}
		siz[i] = len;
		head[i] = 1;
	}
	for(int i = 0 ; i < 26 ; ++i){
		sort(v[i].begin() , v[i].end());
		reverse(v[i].begin() , v[i].end());
		for(int j = 1 ; j < v[i].size() ; ++j){
			int idx1 = v[i][0].second.second;
			int pos1 = v[i][0].first;
			int idx2 = v[i][j].second.second;
			int pos2 = v[i][j].first;
			g[idx1].emplace_back(make_pair(idx2 , pos1 - pos2));
			head[idx2] = 0;
		}
	}
	vector < pair < int , int > > f;
	f.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(head[i]){
			f.emplace_back(make_pair(arr[i][1] , i));
		}
	}
	sort(f.begin() , f.end());
	cur = 0;
	for(auto it : f){
		int x = it.second;
		val[x] = ++cur;
		dfs(x);
	}
	memset(ans , -1 , sizeof(ans));
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= siz[i] ; ++j){
			int here = arr[i][j];
			int idx = val[i] + j - 1;
			if(ans[idx] == -1){
				ans[idx] = here;
				continue;
			}
		}
	}
	int mask = 0;
	for(int i = 1 ; i <= cur ; ++i){
		int val = ans[i];
		if((mask >> val) & 1){
			printf("NO\n");
			return 0;
		}
		mask |= 1 << val;
	}
	for(int i = 1 ; i <= cur ; ++i){
		string tmp = "";
		for(int j = i ; j <= cur ; ++j){
			tmp += char(ans[j] + 'a');
			if(mp.find(tmp) != mp.end()){
				++mp[tmp];
			}
		}
	}
	for(auto it : mp){
		if(it.second != 1){
			printf("NO\n");
			return 0;
		}
	}
	for(int i = 1 ; i <= cur ; ++i){
		printf("%c" , ans[i] + 'a');
	}
	printf("\n");
}
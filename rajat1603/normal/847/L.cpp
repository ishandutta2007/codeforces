#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int S = 1e5 + 5;
int n;
char str[N];
vector < set < int > > v[N];
bool dead[N];
vector < pair < int , int > > ans;
void rip(){
	printf("-1\n");
	exit(0);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		v[i].clear();
		while(1){
			int siz;
			scanf("%d" , &siz);
			v[i].push_back({});
			while(siz--){
				int tmp;
				getchar();
				scanf("%d" , &tmp);
				v[i].back().insert(tmp);
			}
			if(getchar() != '-'){
				break;
			}
		}
	}
	for(int xxx = 1 ; xxx < n ; ++xxx){
		int who = -1;
		for(int i = 1 ; i <= n ; ++i){
			if(dead[i]){
				continue;
			}
			if(v[i].size() == 1){
				who = i;
			}
		}
		if(who == -1){
			rip();
		}
		if(v[who][0].size() != n - xxx){
			rip();
		}
		dead[who] = 1;
		int parent = -1;
		for(int i = 1 ; i <= n ; ++i){
			if(dead[i]){
				continue;
			}
			for(auto &s : v[i]){
				if(s.size() == 1 && *s.begin() == who){
					if(parent != -1){
						rip();
					}
					parent = i;
				}
			}
		}
		if(parent == -1){
			rip();
		}
		ans.push_back({parent , who});
		for(int i = 1 ; i <= n ; ++i){
			if(dead[i]){
				continue;
			}
			for(auto &s : v[i]){
				s.erase(who);
			}
		}
		for(int i = 1 ; i <= n ; ++i){
			if(dead[i]){
				continue;
			}
			for(int j = v[i].size() - 1 ; j >= 0 ; --j){
				if(v[i][j].size() == 0){
					v[i].erase(v[i].begin() + j);
				}
			}
		}
	}
	printf("%d\n" , n - 1);
	for(auto it : ans){
		printf("%d %d\n" , it.first , it.second);
	}
}
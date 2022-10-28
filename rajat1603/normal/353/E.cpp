#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
char str[N];
int n;
int ans;
int out[N];
int in[N];
vector < int > lft[N];
vector < int > rgt[N];
vector < int > onel;
vector < int > oner;
bool matched[N];
bool matchedl[N];
int main(){
	scanf("%s" , str);
	n = strlen(str);
	for(int i = 0 ; i < n ; ++i){
		int a , b;
		if(str[i] == '0'){
			a = i;
			b = (i + 1) % n;
		}
		else{
			b = i;
			a = (i + 1) % n;
		}
		lft[a].emplace_back(b);
		rgt[b].emplace_back(a);
	}
	for(int i = 0 ; i < n ; ++i){
		if(lft[i].size() == 1){
			onel.emplace_back(i);
		}
		if(rgt[i].size() == 1){
			oner.emplace_back(i);
		}
		in[i] = rgt[i].size();
		out[i] = lft[i].size();
	}
	while(!onel.empty() || !oner.empty()){
		while(!onel.empty()){
			int x = onel.back();
			onel.pop_back();
			out[x] = 0;
			for(int y : lft[x]){
				--in[y];
				if(in[y] == 1){
					oner.emplace_back(y);
				}
				if(matched[y] || matchedl[x]){
					continue;
				}
				matched[y] = 1;
				matchedl[x] = 1;
				in[y] = 0;
				++ans;
				for(int z : rgt[y]){
					--out[z];
					if(out[z] == 1){
						onel.emplace_back(z);
					}
				}
			}
		}
		while(!oner.empty()){
			int x = oner.back();
			oner.pop_back();
			in[x] = 0;
			for(int y : rgt[x]){
				--out[y];
				if(out[y] == 1){
					onel.emplace_back(y);
				}
				if(matchedl[y] || matched[x]){
					continue;
				}
				matched[x] = 1;
				matchedl[y] = 1;
				out[y] = 0;
				++ans;
				for(int z : lft[y]){
					--in[z];
					if(in[z] == 1){
						oner.emplace_back(z);
					}
				}
			}
		}
	}
	for(int i = 0 ; i < n ; ++i){
		if(out[i] == 2){
			++ans;
		}
	}
	printf("%d\n" , n - ans);
}
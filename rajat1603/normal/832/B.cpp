#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char good[N];
int mark[26];
int n;
char str[N];
int idx;
int q;
char tmp[N];
int main(){
	scanf("%s" , good);
	memset(mark , 0 , sizeof(mark));
	for(int i = 0 ; good[i] ; ++i){
		mark[good[i] - 'a'] = 1;
	}
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	idx = -1;
	for(int i = 1 ; i <= n ; ++i){
		if(str[i] == '*'){
			idx = i;
		}
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%s" , tmp + 1);
		int m = strlen(tmp + 1);
		if(idx == -1){
			if(n == m){
				bool ok = 1;
				for(int i = 1 ; i <= n ; ++i){
					if(str[i] == '?'){
						if(!mark[tmp[i] - 'a']){
							ok = 0;
						}
					}
					else{
						if(tmp[i] != str[i]){
							ok = 0;
						}
					}
				}
				printf(ok ? "YES\n" : "NO\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			if(n - 1 > m){
				printf("NO\n");
			}
			else{
				bool ok = 1;
				int start , finish;
				for(int i = 1 ; i <= m ; ++i){
					if(str[i] == '*'){
						start = i;
						break;
					}
					if(str[i] == '?'){
						if(!mark[tmp[i] - 'a']){
							ok = 0;
						}
					}
					else{
						if(tmp[i] != str[i]){
							ok = 0;
						}
					}
				}
				finish = n;
				bool rip = 0;
				for(int i = m ; i >= 1 ; --i){
					if(str[finish] == '*'){
						finish = i;
						rip = 1;
						break;
					}
					if(str[finish] == '?'){
						if(!mark[tmp[i] - 'a']){
							ok = 0;
						}
					}
					else{
						if(tmp[i] != str[finish]){
							ok = 0;
						}
					}
					--finish;
				}
				if(!rip){
					finish = 0;
				}
				if(ok){
					for(int i = start ; i <= finish ; ++i){
						if(mark[tmp[i] - 'a']){
							ok = 0;
						}
					}
				}
				printf(ok ? "YES\n" : "NO\n");
			}
		}
	}
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
const int mod = 1e9 + 7;
char str[N];
int arr[N][N];
int n;
int cnt1[N][N][4];/* ------------ */
int cnt2[N][N][4];/* ||||||||||| */
int cnt3[N][N][4];/* \\\\        */
int cnt4[N][N][4]; /* /////////// */
vector < pair < int , int > > ans;
const long double log3 = 1.58496250072115618145373894395;
bool cmp(pair < int , int > a , pair < int , int > b){
	return (a.first + log3 * a.second > b.first + log3 * b.second);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str);
		for(int j = 0 ; j < n ; ++j){
			arr[i][j + 1] = str[j] - '0';
		}
	}
	memset(cnt1 , 0 , sizeof(cnt1));
	memset(cnt2 , 0 , sizeof(cnt2));
	memset(cnt3 , 0 , sizeof(cnt3));
	memset(cnt4 , 0 , sizeof(cnt4));
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			for(int k = 0 ; k < 4 ; ++k){
				cnt1[i][j][k] = cnt1[i][j - 1][k];
			}
			++cnt1[i][j][arr[i][j]];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			for(int k = 0 ; k < 4 ; ++k){
				cnt2[i][j][k] = cnt2[i - 1][j][k];
			}
			++cnt2[i][j][arr[i][j]];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			for(int k = 0 ; k < 4 ; ++k){
				cnt3[i][j][k] = cnt3[i - 1][j - 1][k];
			}
			++cnt3[i][j][arr[i][j]];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			for(int k = 0 ; k < 4 ; ++k){
				cnt4[i][j][k] = cnt4[i - 1][j + 1][k];
			}
			++cnt4[i][j][arr[i][j]];
		}
	}
	ans.clear();
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(arr[i][j]){
				int sz = min(i , n - i + 1);
				sz = min(sz , min(j , n - j + 1));
				int l = 2;
				int r = sz + 1;
				while(l < r){
					int mid = l + r >> 1;
					int x , y;
					y = j;
					x = i - mid + 1;
					bool rekt = 0;
					if(x < 1 || cnt2[i][j][0] - cnt2[x - 1][j][0]){
						rekt = 1;
					}
					x = i + mid - 1;
					if(x > n || cnt2[x][j][0] - cnt2[i - 1][j][0]){
						rekt = 1;
					}
					x = i;
					y = j + mid - 1;
					if(y > n || cnt1[x][y][0] - cnt1[i][j - 1][0]){
						rekt = 1;
					}
					y = j - mid + 1;
					if(y < 1 || cnt1[i][j][0] - cnt1[i][y - 1][0]){
						rekt = 1;
					}
					if(rekt){
						r = mid;
					}
					else{
						l = mid + 1;
					}
				}
				--l;
				--r;
				int cn2 = cnt2[i + l - 1][j][2] - cnt2[i - l][j][2];
				cn2 += cnt1[i][j + l - 1][2] - cnt1[i][j - l][2];
				cn2 -= (arr[i][j] == 2);
				int cn3 = cnt2[i + l - 1][j][3] - cnt2[i - l][j][3];
				cn3 += cnt1[i][j + l - 1][3] - cnt1[i][j - l][3];
				cn3 -= (arr[i][j] == 3);
				ans.emplace_back(make_pair(cn2 , cn3));
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(arr[i][j]){
				int sz = min(i , n - i + 1);
				sz = min(sz , min(j , n - j + 1));
				int l = 2;
				int r = sz + 1;
				while(l < r){
					int mid = l + r >> 1;
					int x , y;
					x = i - mid + 1;
					y = j - mid + 1;
					bool rekt = 0;
					if(min(x , y) < 1 || cnt3[i][j][0] - cnt3[x - 1][y - 1][0]){
						rekt = 1;
					}
					y = j + mid - 1;
					if(x < 1 || y > n || cnt4[i][j][0] - cnt4[x - 1][y + 1][0]){
						rekt = 1;
					}
					x = i + mid - 1;
					y = j - mid + 1;
					if(x > n || y < 1 || cnt4[x][y][0] - cnt4[i - 1][j + 1][0]){
						rekt = 1;
					}
					y = j + mid - 1;
					if(x > n || y > n || cnt3[x][y][0] - cnt3[i - 1][j - 1][0]){
						rekt = 1;
					}
					if(rekt){
						r = mid;
					}
					else{
						l = mid + 1;
					}
				}
				--l;
				--r;
				int cn2 = 0;
				cn2 += cnt3[i + l - 1][j + l - 1][2] - cnt3[i - l][j - l][2];
				cn2 += cnt4[i + l - 1][j - l + 1][2] - cnt4[i - l][j + l][2];
				cn2 -= (arr[i][j] == 2);
				int cn3 = 0;
				cn3 += cnt3[i + l - 1][j + l - 1][3] - cnt3[i - l][j - l][3];
				cn3 += cnt4[i + l - 1][j - l + 1][3] - cnt4[i - l][j + l][3];
				cn3 -= (arr[i][j] == 3);
				ans.emplace_back(make_pair(cn2 , cn3));
			}
		}
	}
	if(ans.empty()){
		cout << "0\n";
		return 0;
	}
	pair < int , int > print = make_pair(0 , 0);
	for(auto it : ans){
		if(cmp(it , print)){
			print = it;
		}
	}
	int answer = 1;
	for(int i = 0 ; i < print.first ; ++i){
		answer = (answer * 2LL) % mod;
	}
	for(int i = 0 ; i < print.second ; ++i){
		answer = (answer * 3LL) % mod;
	}
	printf("%d\n" , answer);
}
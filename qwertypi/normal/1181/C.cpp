#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef int64_t ll;
char graph[1002][1002];

struct record{
	char a, b, c;
	int U, D;
	record(char a, char b, char c, int U, int D):
		a(a), b(b), c(c), U(U), D(D){}
};

ll val(record A){
	return (((ll)A.a << 40) + ((ll)A.b << 31) + ((ll)A.c << 22) + ((ll)(A.U) << 11) + (ll)A.D);
}

struct cmp
{
	bool operator()(record A, record B){
		return val(A) < val(B);
	}
};

map<record, vector<int>, cmp> check;
int main(){
	int r, c;
	cin >> r >> c;
	for(int i=0;i<r;i++){
		cin >> graph[i];
	}
	ll ans = 0;
	for(int i=0;i<c;i++){
		int cnt[3] = {0, 0, 0};
 		char s[5];
 		s[0] = ' ';
 		s[1] = ' ';
 		s[2] = ' ';
		int curCnt = 0;
		for(int j=0;j<r;j++){
			if(graph[j][i] == s[curCnt]){
				cnt[curCnt]++;
			}else{
				curCnt++;
				if(curCnt == 3){
					cnt[0] = cnt[1];
					cnt[1] = cnt[2];
					cnt[2] = 1;
					s[0] = s[1];
					s[1] = s[2];
					s[2] = graph[j][i];
					curCnt--;
				}else{
					cnt[curCnt] = 1;
					s[curCnt] = graph[j][i];
				}
			}
			if(cnt[0] >= cnt[1] && cnt[1] == cnt[2]){
				record now = record(s[0], s[1], s[2], j - cnt[2] * 3 + 1, j);
				if(check.find(now) != check.end()){
					check[now].push_back(i);
				}else{
					check[now] = vector<int>{i};
				} 
 			}
		}
	}
	for(auto i:check){
		vector<int> list = i.second;
		int cnt = 0;
		int res = 0;
		int prev = -2;
		sort(list.begin(), list.end());
		for(auto j:list){
			if(prev + 1 == j){
				cnt++;
			}else{
				res += cnt * (cnt + 1) / 2;
				cnt = 1;
			}
			prev = j;
		}
		res += cnt * (cnt + 1) / 2;
		ans += res;
	}
	cout << ans;
}
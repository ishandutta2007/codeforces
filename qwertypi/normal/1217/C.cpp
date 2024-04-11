#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;

typedef long long ll;

void f(){
	string s;
	cin >> s;
	int ans = 0;
	int curCnt = 0;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == '0'){
			curCnt++;
		}else{
			int curVal = 1;
			for(int j = 0; j < 20 && i + j < (int)s.size(); j++){
				if(j + 1 + curCnt >= curVal && curVal >= j + 1){
					ans++;
				}
				if(i + j + 1 < (int)s.size())
					curVal = curVal * 2 + s[i + j + 1] - '0';
			}
			curCnt = 0;
		}
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		f();
	}
	return 0;
}
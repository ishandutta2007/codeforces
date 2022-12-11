#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

map<string, int> cmp;
map<int, string> ctt;

int cnt[10];


int main(){
	fastIO;
	cmp["S"] = 1;
	cmp["M"] = 2;
	cmp["L"] = 3;
	cmp["XL"] = 4;
	cmp["XXL"] = 5;
	cmp["XXXL"] = 6;
	
	ctt[1] = "S";
	ctt[2] = "M";
	ctt[3] = "L";
	ctt[4] = "XL";
	ctt[5] = "XXL";
	ctt[6] = "XXXL"; 
	int a;
	for(int i = 1; i <= 6; i ++ ){
		cin >> a;
		cnt[i] = a;
	}
	int n;
	cin >> n;
	int as[n];
	memset(as, -1, sizeof as);
	string k;
	vector<vector<int>> tshirts(n);
	string t;
	for(int i = 0;i < n; i ++ ){
		cin >> k;
		t.clear();
		for(char y : k){
			if(y == ','){
				tshirts[i].push_back(cmp[t]);
				t.clear();
			}
			else{
				t.push_back(y);
			}
		}
		tshirts[i].push_back(cmp[t]);
		if(tshirts[i].size() == 1){
			if(cnt[tshirts[i][0]] > 0){
				cnt[tshirts[i][0]] -- ;
				as[i] = tshirts[i][0];
			}
			else{
				cout << "NO\n";
				return 0;
			}
		}
	}
	for(int i = 1; i <= 5; i++ ){
		for(int j = 0;j < n;j ++ ){
			if(tshirts[j].size() > 1){
				if(tshirts[j][0] == i){
					if(cnt[i] > 0){
						cnt[i] -- ;
						as[j] = i;
					}
					else if(cnt[i + 1] > 0){
						cnt[i + 1] -- ;
						as[j] = i + 1;
					}
				}
			}
		}
	}
	for(int i = 0;i < n;i ++ ){
		if(as[i] == -1){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i = 0;i < n;i ++ ){
		cout << ctt[as[i]] << "\n";
	}
	return 0;
}
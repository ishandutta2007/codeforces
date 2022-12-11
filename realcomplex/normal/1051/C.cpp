#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> id[105];
char ans[105];

int main(){
	fastIO;
	int n;
	cin >> n;
	int s[n];
	for(int i = 0;i < n; i++ ){
		cin >> s[i];
		id[s[i]].push_back(i);
	}
	int a = 0, b = 0;
	for(int i = 0;i < 105;i ++ ){
		if(id[i].size() == 0){
			continue;
		}
		else if(id[i].size() == 1){
			if(a <= b){
				ans[id[i][0]] = 'A';
				a ++ ;
			}
			else{
				ans[id[i][0]] = 'B';
				b ++ ;
			}
		}
		else if(id[i].size() == 2){
			ans[id[i][0]] = 'A';
			ans[id[i][1]] = 'B';
			a ++ ;
			b ++ ;
		}
	}
	for(int i = 0;i < 105; i ++ ){
		if(id[i].size() > 2){
			if(a == b){
				for(auto x : id[i])
					ans[x] = 'A';
			}
			else if(a < b){
				ans[id[i][0]] = 'A';
				a ++ ;
				for(int j = 1;j < id[i].size(); j ++ ){
					ans[id[i][j]] = 'B';
				}
			}
			else{
				ans[id[i][0]] = 'B';
				b ++ ;
				for(int j = 1; j < id[i].size(); j ++ ){
					ans[id[i][j]] = 'A';
				}
			}
		}
	}
	if(a != b){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
		for(int i = 0;i < n;i ++ )
			cout << ans[i];
	}
	return 0;
}
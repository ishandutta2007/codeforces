#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 1005;
int cnt[N];
bool is[N];

int main(){
	//fastIO;
	int n;
	cin >> n;
	int ai, bi;
	for(int i = 1; i < n; i ++ ){
		cin >> ai >> bi;
		if(bi != n){
			cout << "NO\n";
			return 0;
		}
		cnt[ai] ++ ;
	}
	vector<pii> ans;
	int p = 1;
	int ls;
	for(int i = 1; i < n; i ++ ){
		if(cnt[i] > 0){
			ls = n;
			cnt[i] --  ;
			is[i] = true;
			while(cnt[i] > 0){
				while(is[p] == true){
					p ++ ;
					if(p > i){
						cout << "NO\n";
						return 0;
					}
				}
				cnt[i] -- ;
				is[p] = true;
				ans.push_back(mp(ls, p));
				ls = p;
			}
			ans.push_back(mp(ls, i));
		}
	}
	cout << "YES\n";
	for(auto x : ans){
		cout << x.fi << " " << x.se << "\n";
	}
	return 0;
}
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

const int N = 205;
int cnt[N][N];

bool use[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	if(n == 2){
		int k;
		cin >> k;
		int x;
		cin >> x;
		cout << 1 << " " << x << "\n";
		cout << k - 1 << " ";
		for(int i = 1 ; i < k; i ++ ){
			cin >> x;
			cout << x << " ";
		}
		cout << "\n";
		return 0;
	}
	int k;
	int x, y;
	for(int i = 0; i < n * (n - 1) / 2; i ++ ){
		cin >> k;
		vector<int> st;
		for(int j = 0;j < k; j ++ ){
			cin >> x;
			st.push_back(x);
		}
		for(int v1 = 0; v1 < k ; v1 ++ ){
			for(int v2 = 0; v2 < k ; v2 ++ ){
				cnt[st[v1]][st[v2]] ++ ;
			}
		}
	}
	for(int v1 = 1; v1 < N ; v1 ++ ){
		if(use[v1])
			continue;
		vector<int> ans;
		for(int v2 = v1; v2 < N; v2 ++ ){
			if(!use[v2] and cnt[v1][v2] > 1){
				ans.push_back(v2);
				use[v2] = true;
			}
		} 
		if(ans.empty())
			continue;
		cout << ans.size() << " ";
		for(auto x : ans)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}
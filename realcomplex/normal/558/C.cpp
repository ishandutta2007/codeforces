#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

int cnt[N];
int dis[N];
int las[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	int a;
	int b;
	int d;
	for(int i = 1; i <= n; i ++ ){
		cin >> a;
		queue<pii> t;
		t.push(mp(a, 0));
		cnt[a] ++ ;
		las[a] = i;
		while(!t.empty()){
			b = t.front().fi;
			d = t.front().se;
			t.pop();
			if(b * 2 < N){
				if(las[b * 2] != i){
					las[b * 2] = i;
					cnt[b * 2] ++ ;
					dis[b * 2] += d + 1;
					t.push(mp(b * 2, d + 1));
				}
			}
			if(b / 2 >= 1){
				if(las[b / 2] != i){
					las[b / 2] = i;
					cnt[b / 2] ++ ;
					dis[b / 2] += d + 1;
					t.push(mp(b / 2, d + 1));
				}
			}
		}
	}
	int answ = (int)1e7;
	for(int i = 1; i < N; i ++ ){
		if(cnt[i] == n){
			answ = min(answ, dis[i]);
		}
	}
	cout << answ << "\n";
	return 0;
}
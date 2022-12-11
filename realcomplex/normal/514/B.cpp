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

bool check(int x1, int y1, int x2, int y2, int x3, int y3){
	return (x1 - x2) * (y2 - y3) == (y1 - y2) * (x2 - x3);
}

int main(){
	fastIO;
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	int xi[n], yi[n];
	int comp[n];
	int cnt = 0;
	int fn;
	for(int i = 0;i < n; i ++ ){
		cin >> xi[i] >> yi[i];
		fn = cnt + 1;
		for(int j = i - 1; j >= 0;j -- ){
			if(check(x0, y0, xi[j], yi[j], xi[i], yi[i])){
				fn = comp[j];
			}
		}
		cnt = max(cnt, fn);
		comp[i] = fn;
	}
	cout << cnt;
	return 0;
}
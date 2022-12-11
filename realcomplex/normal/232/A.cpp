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

const int N = 105;

bool is[N][N];

int f(int x){
	return (x * (x - 1) * (x - 2)) / 6;
}

int main(){
	fastIO;
	int k;
	cin >> k;
	int n = 1;
	while(f(n + 1) <= k){
		n ++ ;
	}
	k -= f(n);
	for(int i = 1;i <= n;i ++ ){
		for(int j = 1;j <= n; j ++ ){
			if(i != j)	
				is[i][j] = true;
		}
	}
	int s = n;
	while(k > 0){
		s ++ ;
		for(int i = 1;i <= n; i++ ){
			if(k >= i - 1){
				k -= i - 1;
				is[s][i] = true;
				is[i][s] = true;
			}
		}
	}
	cout << s << "\n";
	for(int i = 1;i <= s; i ++ ){
		for(int j = 1;j <= s; j ++ ){
			cout << is[i][j];
		}
		cout << "\n";
	}
	return 0; 
}
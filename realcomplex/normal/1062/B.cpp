#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> pr;
vector<int> cnt;

void fact(int x){
	int ct;
	for(int i = 2; i <= 1000000; i ++ ){
		if(x % i == 0){
			ct = 0;
			while(x % i == 0){
				ct ++ ;
				x  /=  i;
			}
			cnt.push_back(ct);
			pr.push_back(i);
		}
	}
}

int mxbit(int t){
	for(int i = 0 ;i <= 23; i ++ ){
		if((1 << i) >= t)
			return i;
	}
}
int main(){
	fastIO;
	int n;
	cin >> n;
	fact(n);
	int t = 1;
	for(auto x : pr){
		t *= x;
	}
	cout << t << " ";
	int r = 0;
    t = 0;
	for(auto x : cnt){
		r = max(r, mxbit(x));
	}
	for(auto x : cnt){
		if(x != (1 << r)){
			t = 1;
		}
	}
	cout << r + t;
	return 0;
}
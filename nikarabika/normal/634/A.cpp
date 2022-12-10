//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int n;
vector<int> vec1, vec2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x)
			vec1.PB(x);
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x)
			vec2.PB(x);
	}
	n--;
	for(int i = 0; i < n; i++)
		if(vec1[i] == 1){
			rotate(vec1.begin(), vec1.begin() + i, vec1.end());
			break;
		}
	for(int i = 0; i < n; i++)
		if(vec2[i] == 1){
			rotate(vec2.begin(), vec2.begin() + i, vec2.end());
			break;
		}
	for(int i = 0; i < n; i++)
		if(vec1[i] != vec2[i]){
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}
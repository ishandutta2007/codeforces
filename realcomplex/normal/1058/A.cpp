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

int main(){
	fastIO;
	int n;
	cin >> n;
	int a;
	for(int i = 0;i < n;i ++ ){
		cin >> a;
		if(a == 1){
			cout << "HARD\n";
			return 0;
		}
	}
	cout << "EASY\n";
	return 0;
}
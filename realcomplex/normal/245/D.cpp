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

int main(){
	fastIO;
	int n;
	cin >> n;
	int bitw = 0;
	int a;
	for(int i = 0;i < n; i++ ){
		bitw = 0;
		for(int j = 0;j < n;j ++ ){
			cin >> a;
			if(a != -1)
				bitw |= a;
		}
		cout << bitw << " ";
		
	}
	return 0;
}
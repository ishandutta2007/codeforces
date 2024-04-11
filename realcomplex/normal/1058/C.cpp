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
	char kd[n];
	for(int i = 0;i < n;i ++ )
		cin >> kd[i];
	int segm = 0;
	bool can;
	int tk;
	for(int i = 0; i <= 1000; i ++ ){
		segm = 0;
		can = true;
		tk = 0;
		for(int j = 0;j < n; j++ ){
			tk += kd[j] - '0';
			if(tk == i)
				tk = 0, segm ++ ;
			else if(tk > i)
				can = false;
				
		}
		if(segm > 1 and can == true and tk == 0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
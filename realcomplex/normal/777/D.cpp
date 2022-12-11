#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
	fastIO;
	int n;
	cin >> n;
	string a[n];
	for(int i = 0;i<n;i++)
		cin >> a[i];
	int l;
	for(int j = n-2;j>=0;j--){
		l = 0; // break point
		for(int x = 0;x<(int)a[j].size();x++){
			if(x > (int)a[j+1].size()){
				l = x;
				break;
			}
			if(a[j][x] > a[j+1][x]){
				l = x;
				break;
			}
			else if(a[j][x] < a[j+1][x])
				break;
		}
		if(l==0) // do nothing
			continue;
		a[j] = a[j].substr(0,l);
	}
	for(int i = 0;i<n;i++){
		cout << a[i] << "\n";
	}
	return 0;
}
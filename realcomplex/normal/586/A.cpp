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
	vector<int>a;
	int k;
	int y = 0;
	for(int i = 0;i<n;i++){
		cin >> k;
		a.push_back(k);
	}
	while(!a.empty()){
		if(a.back() != 0)
			break;
		a.pop_back();
	}
	reverse(a.begin(),a.end());
	while(!a.empty()){
		if(a.back() != 0)
			break;
		a.pop_back();
	}
	reverse(a.begin(),a.end());
	int l = 0;
	n = a.size();
	int j = 0;
	while(j < n){
		if(j == n-1){
			l ++ ;
			j++;
			continue;
		}
		if(a[j] == 0 and a[j+1] == 0){
			while(a[j] == 0)
				j++;
		}
		else{
			j++;
			l++;
		}
	}
	cout << l ;
	return 0;
}
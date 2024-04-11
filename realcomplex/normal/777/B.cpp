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

int cnt[10];

int main(){
	fastIO;
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	sort(a.begin(),a.end());
	for(auto x : b)
		cnt[x-48]++;
	int l = 0;
	int r;
	int k;
	for(auto x : a){
		r = x-48;
		k = r;
		for(int i = 0;i<10;i++){
			if(cnt[k] >= 1){
				if(k < r)l++;
				cnt[k]--;
				break;
			}
			k++;
			k %= 10;
		}
	}
	for(auto x : b)
		cnt[x-48]++;
	cout << l << "\n";
	l = 0;
	for(auto x : a){
		r = x-48;
		k = r;
		for(int i = 0;i<10;i++){
			k++;
			k %= 10;
			if(cnt[k]>=1){
				if(k > r)l++;
				cnt[k]--;
				break;
			}
		}
	}
	cout << l << "\n";
	return 0;
}
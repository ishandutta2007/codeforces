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
	string s;
	cin >> n >> s;
	for(int i= 1;i<s.size();i++){
		if(s[i] != '?' and s[i-1] == s[i]){
			cout << "No\n";
			return 0;
		}
	}
	bool h = false;
	for(int i = 0;i<n;i++){
		if(i==0){
			if(s[i] == '?'){
				cout << "Yes\n";
				return 0;
			}
		}
		else if(i == n-1){
			if(s[i] == '?'){
				cout << "Yes\n";
				return 0;
			}
		}
		else{
			if(s[i] == '?'){
				if(s[i-1] == s[i+1] || s[i-1] == '?' || s[i+1] == '?'){
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
cout << "No";
	return 0;
}
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

int cnt[26];
int cnt1 = 0; 
int u = 0;

int main(){
	fastIO;
	string c;
	cin >> c;
	for(auto x : c){
		cnt[x - 97] ++ ;
		if(cnt[x- 97] == 1)
			u++;
	}
	for(int i = 0;i<26;i++)
		if(cnt[i] == 1)
			cnt1++;
	if(u == 1 or c.size() <= 3){
		cout << "No";
	}
	else if(u == 2 and cnt1 == 1){
		cout << "No";
	}
	else if(u == 2 and cnt1 != 1){
		cout << "Yes";
	}
	else if(u == 3){
		if(c.size() == 3){
			cout << "No";
		}
		else{
			cout << "Yes";
		}
	}
	else if(u == 4){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}
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

const int N = (int)2e5 + 9;

int main(){
	string s;
	while(cin >> s){
		int n = s.size();
		if(s[n-1] == '1' or s[0] == '1'){
			cout << -1 << "\n\n";
			continue;
		}
		bool is = true;
		vector<int>seq[N];
		queue<int>zer,one;
		int l = 1;
		for(int i = 0;i<s.size();i++){
			if(s[i] == '0'){
				if(zer.empty()){
					seq[l++].push_back(i+1);
					one.push(l-1);
				}
				else{
					seq[zer.front()].push_back(i+1);
					one.push(zer.front());
					zer.pop();
				}
			}else{
				if(one.empty()){
					is = false;
					break;
				}
				else{
					seq[one.front()].push_back(i+1);
					zer.push(one.front());
					one.pop();
				}
			}
		}
		int sum = 0;
		for(int i = 1;i<=l;i++)
			sum += seq[i].size();
		if(is == false or sum != n or !zer.empty()){
			cout << -1 << "\n\n";
			continue;
		}
		cout << --l << "\n";
		for(int i = 1;i<=l;i++){
			cout << seq[i].size() << " ";
			for(auto x : seq[i])
				cout << x << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
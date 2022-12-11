#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<char, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	string t;
	cin >> t;
	vector<char> st;
	int answ =0 ;
	int n;
	for(int i = 0; i < t.size(); i ++ ){
		st.push_back(t[i]);
		while(st.size() >= 2){
			n = st.size();
			if(st[n - 1] == st[n - 2]){
				answ ++ ;
				st.pop_back();
				st.pop_back();
			}
			else{
				break;
			}
		}
	}
	if(answ % 2 == 0)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}
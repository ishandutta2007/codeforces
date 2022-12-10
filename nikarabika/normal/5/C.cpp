#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	stack<pair<char, int> > st;
	st.push(MP(')', -1));
	int Max = 0, cnt = 1;
	for(int i = 0; i < sz(s); i++){
		if(s[i] == ')' and st.top().L == '('){
			st.pop();
			if(i - st.top().R > Max)
				Max = i - st.top().R, cnt = 0;
			cnt += i - st.top().R == Max;
		}
		else
			st.push(MP(s[i], i));
	}
	cout << Max << ' ' << cnt << endl;
	return 0;
}
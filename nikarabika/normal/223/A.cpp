#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pie;

const int maxn = 1e5 + 75 - 65;
bool a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	stack <pair<char, int> > suck;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(' or s[i] == '[')
			suck.push(MP(s[i], i));
		else if(s[i] == ')'){
			if(!suck.size() or suck.top().L == '[')
				while(suck.size())
					suck.pop();
			else{
				a[suck.top().R] = a[i] = true;
				suck.pop();
			}
		}
		else{
			if(!suck.size() or suck.top().L == '(')
				while(suck.size())
					suck.pop();
			else{
				a[suck.top().R] = a[i] = true;
				suck.pop();
			}
		}
	}
	int l = 0, r = 0;
	int Max = 0;
	pie ans;
	while(l < s.size()){
		int cnt = 0;
		while(r < s.size() and a[r]){
			cnt += s[r] == '[';
			r++;
		}
		if(cnt > Max){
			Max = cnt;
			ans = MP(l, r - l);
		}
		if(l == r)
			r++;
		l = r;
	}
	cout << Max << endl;
	if(Max)
		cout << s.substr(ans.L, ans.R) << endl;
	return 0;
}
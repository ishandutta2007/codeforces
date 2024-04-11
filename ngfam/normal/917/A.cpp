#include <bits/stdc++.h>

using namespace std;

const int N = 5501;

bool match[N];

int main(){

	string s;
	cin >> s;

	int n = s.size();

	int ans = 0;

	for(int i = 0; i < n; ++i){
		memset(match, 0, sizeof match);

		deque < int > ques;
		deque < int > op;
		deque < int > wait;

		int found = 0;

		for(int j = i; j < n; ++j){
			if(s[j] == '?'){
				if(wait.size()) {
					found += (match[wait.front()] = 1);
					wait.pop_front();
				}
				ques.push_back(j);
			}
			if(s[j] == '('){
				wait.push_back(j);
				op.push_back(j);
			}
			if(s[j] == ')'){
				if(!ques.size() && !op.size()){
					break;
				}

				if(op.size()){
					if(match[op.back()]) found -= match[op.back()];
					else wait.pop_back();

					op.pop_back();
				}
				else ques.pop_back();
			}
			if(i % 2 != j % 2 && found >= op.size()) {
				++ans;
			}
		}
	}	

	cout << ans;
	return 0;
	
}
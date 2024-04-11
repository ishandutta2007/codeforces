#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
string line[mxN];

void trim(string &s) {
	int pos=0;
	for (; pos<s.size()&&s[pos]==' '; ++pos);
	s=s.substr(pos);
	while(s.back()==' ') s.pop_back();
}
string getThrow(string &s) {
	string res;
	for (int i=0, cnt=0; s[i]!=')'; ++i) {
		if (s[i]==' ') continue;
		if (cnt>=6) res.push_back(s[i]);
		++cnt;
	}
	return res;
}
ar<string, 2> getCatch(string &s) {
	ar<string, 2> res;
	int pos=0, cnt=0;
	for (int i=pos; s[i]!=','; ++i) {
		if (s[i]==' ') continue;
		if (cnt>=6) res[0].push_back(s[i]);
		++cnt;
	}
	int f=-1, l=-1;
	for (int i=pos+1; s[i]!=')'; ++i) {
		if (s[i]=='\"') {
			if (f==-1) f=i;
			else l=i;
		}
	}
	assert(f!=-1&&l!=-1);
	res[1]=s.substr(f+1, l-f-1);
	return res;
}

set<string> pat[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	getline(cin, line[0]); //to avoid reading first line where n is
	for (int i=0; i<n; ++i) {
		getline(cin, line[i]);
		trim(line[i]);
		//cout << line[i] << "\n";
	}
	int depth=0;
	for (int i=0; i<n; ++i) {
		if (line[i]=="") continue;
		if (line[i].substr(0, 3)=="try") {
			++depth;
		}
		else if (line[i].substr(0, 5)=="throw") {
			string s=getThrow(line[i]);
			//for (int j=1; j<=depth; ++j) pat[j].insert(s);
			pat[depth].insert(s);
		}
		else {
			assert(line[i].substr(0, 5)=="catch");
			ar<string, 2> s=getCatch(line[i]);
			if (pat[depth].find(s[0])!=pat[depth].end()) {
				cout << s[1];
				return 0;
			}
			//pat[depth].clear();
			if (pat[depth].size()>pat[depth-1].size()) swap(pat[depth], pat[depth-1]);
			for (const string &x : pat[depth]) pat[depth-1].insert(x);
			pat[depth].clear();
			--depth;
		}
	}
	cout << "Unhandled Exception";
	return 0;
}
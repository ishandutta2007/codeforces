#include <iostream>
#include <vector>
using namespace std;

int f(string p, string s){ // pattern, string
	string c = p + '|' + s;
	vector<int> pre(c.size());
	pre[0] = 0;
	for(int i=1; i<c.size(); i++){
		int curI = i;
		while(curI != 0){
			if(c[pre[curI-1]] == c[i]){
				pre[i] = pre[curI-1] + 1;
				break;
			}else{
				pre[i] = 0;
				curI = pre[curI-1];
			}
		}
	}
	return pre[c.size()-1];
}

int main(){
	int n;
	string s;
	cin >> n;
	for(int i=0;i<n;i++){
		string si;
		cin >> si;
		int len = min(s.size(), si.size());
		int common = f(si.substr(0, len), s.substr(s.size() - len, len));
		s += si.substr(common, si.size() - common);
	}
	cout << s;
}
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, char>> arr(100000);
map<int, vector<int>> useful; 
vector<string> words(100000);
pair<int, char> n_v(string s){
	int res = 0;
	char last = '?';
	for(auto i:s){
		if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
			last = i;
			res++;
		}
	}
	return pair<int, char>{res, last};
}

int cmp(int a, int b){
	return arr[a].second > arr[b].second;
}

vector<pair<string, string>> great;
vector<pair<string, string>> normal;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		words[i] = s;
		arr[i] = n_v(s);
		if(useful.find(arr[i].first) != useful.end()){
			useful[arr[i].first].push_back(i);
		}else{
			useful[arr[i].first] = vector<int>{i};
		}
	}
	for(auto j:useful){
		vector<int> list = j.second;
		sort(list.begin(), list.end(), cmp);
		vector<int> res;
		int i=0;
		while(i < list.size()-1){
			if(arr[list[i]].second == arr[list[i+1]].second){
				great.push_back(pair<string, string>{words[list[i]], words[list[i+1]]});
				i += 2;
			}else{
				res.push_back(list[i]);
				i++;
			}
		}
		if(i == list.size()-1){
			res.push_back(list[i]);
		}
		while(res.size() >= 2){
			int a = res.back();
			res.pop_back();
			int b = res.back();
			res.pop_back();
			normal.push_back(pair<string, string>{words[a], words[b]});
		}
	}
	int ans = min(great.size(), (great.size()+normal.size())/2);
	cout << ans << endl;
	while(great.size() > 1){
		if(normal.size()){
			pair<string, string> a = great.back();
			pair<string, string> b = normal.back();
			great.pop_back(); normal.pop_back();
			cout << b.second << ' ' << a.second << endl;
			cout << b.first << ' ' <<  a.first << endl;
		}else{
			pair<string, string> a = great.back();
			great.pop_back();
			pair<string, string> b = great.back();
			great.pop_back();
			cout << b.second << ' ' << a.second << endl;
			cout << b.first << ' ' << a.first << endl;
		}
	}
	if(great.size() == 1 && normal.size() != 0){
		pair<string, string> a = great.back();
		pair<string, string> b = normal.back();
		great.pop_back(); normal.pop_back();
		cout << b.second << ' ' << a.second << endl;
		cout << b.first << ' ' << a.first << endl;
	}
}
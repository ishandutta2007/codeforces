#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

struct data{
	string real_name;
	string used_name;
	data(string _r, string _u) : real_name(_r), used_name(_u){};
	data(){};
};

map<string, data> to_data;
int main(){
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		string s, t;
		cin >> s >> t;
		if(to_data.find(s) != to_data.end()){
			to_data[t].real_name = to_data[s].real_name;
			to_data[t].used_name = t;
			to_data.erase(s);
		}else{
			to_data[t].real_name = s;
			to_data[t].used_name = t;
		}
	}
	cout << to_data.size() << endl;
	for(auto i:to_data){
		data se = i.second;
		cout << se.real_name << ' ' << se.used_name << endl;
	}
}
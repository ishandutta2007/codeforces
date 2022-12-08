#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct pl{
	string name;
	int id1, id2;
	pl(){}
	pl(string _n, int _i1, int _i2){
		name = _n, id1 = _i1, id2 = _i2;
	}
	bool operator < (const pl &a) const{
		if(id1 != a.id1)
			return id1 < a.id1;
		return id2 < a.id2;
	}
};

int getid(string str){
	if(str == "captain")
		return 3;
	if(str == "man")
		return 2;
	if(str == "woman" || str == "child")
		return 1;
	if(str == "rat")
		return 0;
}

pl arr[110];

int main(){
	int n;
	while(cin >> n){
		string tmp;
		for(int i = 0; i < n; i++){
			cin >> arr[i].name >> tmp;
			arr[i].id1 = getid(tmp);
			arr[i].id2 = i;
		}
		sort(arr, arr + n);
		for(int i = 0; i < n; i++)
			cout << arr[i].name << endl;
	}
	return 0;
}
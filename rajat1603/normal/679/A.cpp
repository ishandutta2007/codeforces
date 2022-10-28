#include "bits/stdc++.h"
using namespace std;
const int arr[4] = {2 , 3 , 5 , 7};
string str[5];
const int arr2[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97};
int found;
int main(){
	found = -1;
	for(int i = 0 ; i < 4 ; ++i){
		cout << arr[i];
		cout << endl;
		fflush(stdout);
		cin >> str[i];
		if(str[i] == "yes"){
			found = arr[i];
			break;
		}
	}
	if(found == -1){
		cout << "prime";
		cout << endl;
		fflush(stdout);
		return 0;
	}
	int sz = sizeof(arr2) / sizeof(arr2[0]);
	bool ok = 0;
	for(int i = 0 ; i < sz ; ++i){
		if(arr2[i] > (100 / found)){
			break;
		}
		if(arr2[i] <= found){
			continue;
		}
		cout << arr2[i] << endl;
		fflush(stdout);
		string tmp;
		cin >> tmp;
		if(tmp == "yes"){
			ok = 1;
			break;
		}
	}
	if(ok){
		cout << "composite\n";
	}
	else{
		const int arr3[] = {4 , 9 , 25 , 49};
		for(int i = 0 ; i < 4 ; ++i){
			cout << arr3[i];
			cout << endl;
			string str;
			cin >> str;
			if(str == "yes"){
				cout << "composite\n";
				return 0;
			}
		}
		cout << "prime\n";
	}
	fflush(stdout);
}
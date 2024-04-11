#include "bits/stdc++.h"
using namespace std;
const int N = 105;
string str;
int n;
string arr[N];
int main(){
	cin >> str;
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == str){
			cout << "YES\n";
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(arr[i][1] == str[0] && arr[j][0] == str[1]){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
}
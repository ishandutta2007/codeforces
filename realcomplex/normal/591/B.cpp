#include <bits/stdc++.h>

using namespace std;

int rep[26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	char arr[n];
	cin >> arr;
	for(int j = 0;j<26;j++)rep[j] = j;
	char t,r;
	int d1,d2;
	for(int i = 0;i<m;i++){
		cin >> t >> r;
		d1 = t-97;
		d2 = r-97;
		for(int j = 0;j<26;j++){
			if(rep[j]==d1)rep[j]=d2;
			else if(rep[j]==d2)rep[j]=d1;
		}
	}
	for(char x : arr){
		cout << char(rep[x-97]+97);
	}
	cout << endl;
	return 0;
}
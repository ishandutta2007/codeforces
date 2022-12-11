#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	char c;
	map<char,int>has;
	int ans = 0;
	for(int j = 1;j<=(n*2)-2;j++){
		cin >> c;
		if(j%2==1)has[char(c-32)]++;
		else{
			if(has[c]==0){
				has[c]=1;
				ans++;
			}
			has[c]--;
		}
	}
	cout << ans << endl;
	return 0;
}
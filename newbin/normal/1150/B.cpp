#include<iostream>
#include<algorithm>
using namespace std;
int n;
char mp[100][100];
bool ok(int i,int j){
	if(i <0 || i >= n || j < 0 || j >= n) return false;
	if(mp[i][j] != '.') return false;
	return true;
}
bool f(int i,int j){
	if(ok(i,j)) mp[i][j] = '#';
	else return false;
	if(ok(i+1,j)) mp[i+1][j] = '#';
	else return false;
	if(ok(i+2,j)) mp[i+2][j] = '#';
	else return false;
	if(ok(i+1,j-1)) mp[i+1][j-1] = '#';
	else return false;
	if(ok(i+1,j+1)) mp[i+1][j+1] = '#';
	else return false;
	return true;
}
int main(){
	cin>>n;
	for(int i = 0;i < n;++i) scanf("%s",mp[i]);
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){
			if(mp[i][j] == '.'){
				if(f(i,j)) continue;
				else{
					cout<<"NO"<<endl;return 0;
				}
			}
		}
	}
	cout<<"YES"<<endl;
}
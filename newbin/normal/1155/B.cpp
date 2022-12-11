#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	cin>>s;
	int cnt = 0;
	for(int i = 0;i < n - 10;++i){
		if(s[i] == '8') cnt++;
	}
	if(2*cnt > n - 10) printf("YES\n");
	else printf("NO\n");
}
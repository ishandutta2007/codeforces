#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	cin>>s;
	for(int i = 1;i < n;++i){
		if(s[i] < s[i-1]){
			printf("YES\n");
			printf("%d %d",i,i+1);return 0;
		}
	}
	printf("NO\n");
}
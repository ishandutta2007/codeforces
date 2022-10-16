#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int res;
int main(){
	cin>>s;
	for(char ch:s){
		if(isdigit(ch)){
			if((ch-'0')&1) res++;
		}else{
			if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
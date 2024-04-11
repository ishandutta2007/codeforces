#include<bits/stdc++.h>
using namespace std;
void solve(){
	string a,b;
	cin>>a>>b;swap(a,b);
	if(a.size()<b.size()){
		puts("NO");return ;
	}
	sort(b.begin(),b.end());
	for(int i=0;i<a.size()-b.size()+1;i++){
		string t=a.substr(i,b.size());
		sort(t.begin(),t.end());
		if(t==b){
			puts("YES");return ;
		}
	}
	puts("NO");
} 
int main(){
	int t;
	cin>>t;
	while(t--)solve(); 
	return 0;
}
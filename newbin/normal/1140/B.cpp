#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
int n;
char s[10000];
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n;
		scanf("%s",s);
		if(s[0] == '<' && s[n-1] == '>') {
			int len1 = 0;
			int len2 = 0;
			for(int i = 0;i < n;++i) if(s[i]=='<') len1++;else break;
			for(int i = n-1;i >= 0;--i) if(s[i] == '>') len2++;else break;
			cout<<min(len1,len2)<<endl;
		}
		else cout<<0<<endl;
	}
}
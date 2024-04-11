#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;string b;
}s[3];
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	int i;
	for(i=0;i<3;i++){
		string t;
		cin>>t;
		s[i].a=t[0]-48;
		s[i].b=t.substr(1,1);
	}
	sort(s,s+3,cmp);
	if(s[0].a==s[1].a&&s[0].a==s[2].a&&s[0].b==s[1].b&&s[0].b==s[2].b){
		cout<<0;return 0;
	}
	if(s[0].a==s[1].a&&s[0].b==s[1].b){
		cout<<1;return 0;
	}
	if(s[1].a==s[2].a&&s[1].b==s[2].b){
		cout<<1;return 0;
	}
	if(s[0].a==s[2].a&&s[0].b==s[2].b){
		cout<<1;return 0;
	}
	if(s[0].a==s[1].a-1&&s[0].a==s[2].a-2&&s[0].b==s[1].b&&s[0].b==s[2].b){
		cout<<0;return 0;
	}
	if(s[0].a==s[1].a-1&&s[0].b==s[1].b){
		cout<<1;return 0;
	}
	if(s[1].a==s[2].a-1&&s[1].b==s[2].b){
		cout<<1;return 0;
	}
	if(s[0].a==s[1].a-2&&s[0].b==s[1].b){
		cout<<1;return 0;
	}
	if(s[1].a==s[2].a-2&&s[1].b==s[2].b){
		cout<<1;return 0;
	}
	if(s[0].a==s[2].a-2&&s[0].b==s[2].b){
		cout<<1;return 0;
	}
	if(s[0].a==s[2].a-1&&s[0].b==s[2].b){
		cout<<1;return 0;
	}
	cout<<2;
	return 0;
}
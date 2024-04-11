#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int u,l,r,d,n=s.size();
		u=l=r=d=0;
		for(int i=0;i<n;i++){
			if(s[i]=='U'){
				u++;
			}else if(s[i]=='L'){
				l++;
			}else if(s[i]=='R'){
				r++;
			}else{
				d++;
			}
		}
		int a=min(l,r),b=min(u,d);
		if(!a||!b){
			if(!a){
				if(b){
					puts("2\nUD");
				}else{
					puts("0");
				}
			}else{
				if(a){
					puts("2\nLR");
				}else{
					puts("0");
				}
			}
			continue;
		}
		cout<<((a+b)<<1)<<'\n';
		for(int i=0;i<a;i++)putchar('L');
		for(int i=0;i<b;i++)putchar('U');
		for(int i=0;i<a;i++)putchar('R');
		for(int i=0;i<b;i++)putchar('D');
		putchar('\n');
	}
	return 0;
}
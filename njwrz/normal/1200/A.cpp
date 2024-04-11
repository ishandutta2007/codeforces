#include <bits/stdc++.h>
using namespace std;
#define pd push_back
#define ve vector
#define ll long long 
#define qu queue
#define pq priority_queue
int f[11];
int main(){
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='L'){
			for(int j=0;j<10;j++){
				if(f[j]==0){
					f[j]=1;break;
				}
			}
		}else if(s[i]=='R'){
			for(int j=9;j>=0;j--){
				if(f[j]==0){
					f[j]=1;break;
				}
			}
		}else {
			f[s[i]-'0']=0;
		}
	}
	for(int i=0;i<10;i++)cout<<f[i];
	return 0;
}
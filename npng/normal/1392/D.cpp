#include <bits/stdc++.h>
using namespace std;
const int Maxn=200000;
int _,n;
char s[Maxn+5];
int main(){
	for(scanf("%d",&_);_--;){
		scanf("%d%s",&n,s);
		int ans;
		if(n%3==0){
			ans=n/3;
		}
		else{
			ans=n/3+1;
		}
		for(int i=1;i<n;i++){
			if(s[i]!=s[i-1]){
				rotate(s,s+i,s+n);
				int cur=1;
				ans=0;
				for(int i=0;i<n;i++){
					if(s[i]!=s[i+1]){
						ans+=cur/3;
						cur=1;
					}
					else{
						cur++;
					}
				}
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
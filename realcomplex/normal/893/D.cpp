#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,d;
	scanf("%I64d %I64d",&n,&d);
	ll k;
	ll s = 0;
	ll org = 0;
	ll l = 0;
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		cin >> k;
		org += k;
		s += k;
		if(org>d){
			printf("-1\n");
			exit(0);
		}
		if(org<0&&k==0){
			org = 0;
		}
		if(s>d){
			if(s-d>l){
				printf("-1\n");
				exit(0);
			}
			else{
				l -= s-d;
				s = d;	
			}
		}
		if(k==0&&s<0){
			s = d;
			l+=d;	
			ans++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
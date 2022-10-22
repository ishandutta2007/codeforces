#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,Q;
char s[N];
int main(){
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	int ans=0;
	auto chk=[&](int i)->int{
		if(i>1&&i<n){
			return s[i-1]=='a'&&s[i]=='b'&&s[i+1]=='c';
		}else{
			return 0;
		}
	};
	rep(i,1,n){
		ans+=chk(i);
	}
	rep(_,1,Q){
		int i;
		scanf("%d",&i);
		int c;
		while(!islower(c=getchar()));
		ans-=chk(i-1),ans-=chk(i),ans-=chk(i+1);
		s[i]=c;
		ans+=chk(i-1),ans+=chk(i),ans+=chk(i+1);
		printf("%d\n",ans);
		
	}
	return 0;
}
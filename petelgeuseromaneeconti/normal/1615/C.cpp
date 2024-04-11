#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n;
char s[N],t[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		scanf("%s%s",s+1,t+1);
		if(!strcmp(s+1,t+1)){
			puts("0");
			continue;
		}
		if(count(t,t+n+1,'1')==0||count(s,s+n+1,'1')==0){
			puts("-1");
			continue;
		}
		int cnt[2][2]={0,0};
		rep(i,1,n){
			++cnt[s[i]-'0'][t[i]-'0'];
		}
		int ans=1e9;
		if(cnt[0][1]==cnt[1][0]){ // 
			ans=min(ans,cnt[0][1]*2);
		}
		if(cnt[0][0]+1==cnt[1][1]){ // 
			ans=min(ans,cnt[1][1]*2-1);
		}
		if(ans==1e9){
			puts("-1");
		}else{
			pt(ans,'\n');
		}
	}
	return 0;
}
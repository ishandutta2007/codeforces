#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,a,b,c;
char s[maxn];
ll ans;
void solve(bool f){
	int cnt1=0,cnt2=0,l=0,cnt3=0,cnt4=0;
	priority_queue<ll,vector<ll>,greater<ll>> s1,s2;
	for(int i=1;i<=n;i++)
		if(s[i]=='1'){
			cnt1++;
			if(i==1||s[i-1]=='0') cnt2++;
		}
		else{
			l++;
			if(i==n||s[i+1]=='1'){
				if(i==l||i==n){
					if(l==1) cnt3++;
					else s1.push(l);
				}
				else{
					if(l==1) cnt4++;
					else s2.push(l);
				}
				l=0;
			}
		}
	ll res=0;
	auto upd=[&res](int x){
		res+=x;
		ans=max(ans,res);
	};
	while(1){
		if(f){
			if(cnt1>cnt2){
				cnt1--;
				upd(b);
			}
			else break;
		}
		else{
			if(cnt1>cnt2){
				if(s2.size()){
					int u=s2.top();
					s2.pop();
					if(u>2) s2.push(u-1);
					else cnt4++;
					upd(a);
				}
				else if(s1.size()){
					int u=s1.top();
					s1.pop();
					if(u>2) s1.push(u-1);
					else cnt3++;
					upd(a);
				}
				else if(cnt4){
					cnt4--;
					cnt2--;
					upd(-c);
				}
				else if(cnt3){
					cnt3--;
					upd(-c);
				}
				else break;
			}
			else{
				if(s1.size()||s2.size()) ans=max(ans,res+a);
				if(cnt4){
					cnt4--;
					cnt2--;
					upd(-c);
				}
				else break;
			}
		}
		f^=1;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		a=readint();
		b=readint();
		c=readint();
		scanf("%s",s+1);
		ans=0;
		solve(1);
		solve(0);
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
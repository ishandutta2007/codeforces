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
int n;
char a[maxn],b[maxn];
bool check(int c1,int c2){
	if(!c1) return 1;
	if(c1==1) return c2==1;
	int x=c1%2==0?c1-2:c1-1,y=c1%2==0?c1-1:c1-2;
	return c2-x/2>0&&c1-c2-y/2>0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",a+1,b+1);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
			if(a[i]==b[i]) cnt1++;
			else cnt2++;
		int ans=2e9,cnt3=0;
		for(int i=1;i<=n;i++) cnt3+=a[i]==b[i]&&a[i]=='1';
		if(cnt1%2==1&&check(cnt1,cnt3)) ans=min(ans,cnt1);
		cnt3=0;
		for(int i=1;i<=n;i++) cnt3+=a[i]!=b[i]&&a[i]=='1';
		if(cnt2%2==0&&check(cnt2,cnt3)) ans=min(ans,cnt2);
		printf("%d\n",ans<2e9?ans:-1);
	}
	/*
	cnt3-x/2
	cnt-cnt3-x/2
	*/
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
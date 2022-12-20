#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,s[maxn];
char a[maxn];
vector<int> vec;
vector<pair<int,int>> ans;
int get(int l,int k){
	return vec[s[l-1]+k-1];
}
void solve(int l,int r,int y){
	int x=s[r]-s[l-1];
	if(x>11){
		int p=get(l,x/2);
		solve(l,p,y/2);
		solve(p+1,r,y/2);
	}
	else if(x==y) for(int i=l;i<=r;i++) ans.push_back({i,i});
	else if(y<=x*3/2){
		int p=get(l,1);
		for(int i=l;i<p;i++) ans.push_back({i,i});
		ans.push_back({p,p+1});
		for(int i=p+2;i<=get(l,2);i++) ans.push_back({i,i});
		solve(get(l,2)+1,r,y-3);
	}
	else if(x==10||x==8){
		int p=get(l,4);
		solve(l,p,8);
		solve(p+1,r,8);
	}
	else if(x==9||x==4){
		int p=get(l,1);
		for(int i=l;i<p;i++) ans.push_back({i,i});
		ans.push_back({p,p+2});
		solve(p+3,r,y-((a[p]-'0')<<2|(a[p+1]-'0')<<1|(a[p+2]-'0')));
	}
	else if(x==7){
		int p=get(l,3);
		solve(l,p,3);
		solve(p+1,r,8);
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		scanf("%s",a+1);
		n=strlen(a+1);
		vec.clear();
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i]-'0';
			if(a[i]=='1') vec.push_back(i);
		}
		if(!s[n]){
			printf("-1\n\n");
			continue;
		}
		ans.clear();
		if(s[n]==5){
			if(vec[4]==vec[0]+4){
				for(int i=1;i<vec[0];i++) ans.push_back({i,i});
				ans.push_back({vec[0],vec[3]});
				for(int i=vec[4];i<=n;i++) ans.push_back({i,i});
			}
			else for(int i:vec) if(a[i+1]=='0'){
				for(int j=1;j<i;j++) ans.push_back({j,j});
				ans.push_back({i,i+2});
				for(int j=i+3;j<=n;j++) ans.push_back({j,j});
				break;
			}
		}
		else{
			int y=1;
			while(y<s[n]) y*=2;
			solve(1,n,y);
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d %d\n",x.first,x.second);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
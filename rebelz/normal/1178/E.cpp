#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[1000005];
vector<int> k;
set<int> t[4];

bool dp(int l,int r,int x){
	if(l>r){
		if(x<n/2) return false;
		for(int i=0;i<k.size();i++) printf("%c",k[i]+'a'-1);
		for(int i=k.size()-1;i>=0;i--) printf("%c",k[i]+'a'-1);
		printf("\n");
		return true;
	}
	if(l==r){
		if(x+1<n/2) return false;
		for(int i=0;i<k.size();i++) printf("%c",k[i]+'a'-1);
		printf("%c",s[l]);
		for(int i=k.size()-1;i>=0;i--) printf("%c",k[i]+'a'-1);
		printf("\n");
		return true;
	}
	int maxa=-1,cho=-1,lf,rg;
	for(int i=1;i<=3;i++){
		if(t[i].lower_bound(l)==t[i].end()) continue;
		if(t[i].upper_bound(r)==t[i].begin()) continue;
		lf=*t[i].lower_bound(l);
		rg=*(--t[i].upper_bound(r));
		if(rg-lf+1>maxa){
			maxa=rg-lf+1;
			cho=i;
		}
	}
	lf=*t[cho].lower_bound(l);
	rg=*(--t[cho].upper_bound(r));
	if(lf==rg){
		if(x+1<n/2) return false;
		for(int i=0;i<k.size();i++) printf("%c",k[i]+'a'-1);
		printf("%c",s[l]);
		for(int i=k.size()-1;i>=0;i--) printf("%c",k[i]+'a'-1);
		printf("\n");
		return true;
	}
	k.push_back(cho);
	return dp(lf+1,rg-1,x+2);
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) t[s[i]-'a'+1].insert(i);
	if(!dp(1,n,0)) cout<<"IMPOSSIBLE\n";
	return 0;
}
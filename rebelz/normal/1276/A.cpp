#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
vector<int> ans;
char s[1500005];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1); n=strlen(s+1);
		ans.clear();
		int ls1=2,ls2=1;
		for(int i=3;i<=n;i++){
			if(s[ls2]=='o'&&s[ls1]=='n'&&s[i]=='e'){
				if(s[i]==s[i+1]) ans.push_back(ls1),ls1=i;
				else ans.push_back(i);
			}
			else if(s[ls2]=='t'&&s[ls1]=='w'&&s[i]=='o'){
				if(s[i]==s[i+1]) ans.push_back(ls1),ls1=i;
				else ans.push_back(i);
			}
			else ls2=ls1,ls1=i;
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d ",x);
		printf("\n");
	}
	return 0;
}
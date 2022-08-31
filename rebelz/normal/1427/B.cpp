#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
char s[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		scanf("%s",s+1);
		int lst=0,ans=0,sum=0;
		vector<int> v(0);
		for(int i=1;i<=n;i++){
			if(s[i]=='W'){
				ans++;
				if(lst&&lst==i-1) ans++;
				if(lst&&i-lst-1) v.pb(i-lst-1);
				else if(i-lst-1) sum+=i-lst-1;
				lst=i;
			}
		}
		if(!lst){
			if(k) printf("%d\n",2*min(n,k)-1);
			else printf("0\n");
			continue;
		}
		sum+=n-lst;
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(k>=v[i]){
				ans+=v[i]*2;
				ans++;
				k-=v[i];
			}
			else{
				ans+=k*2;
				k=0;
			}
		}
		printf("%d\n",ans+min(sum,k)*2);
	}
	return 0;
}
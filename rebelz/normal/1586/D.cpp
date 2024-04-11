#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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
int res[105],a[105];
bool vis[105];

int query(vector<int> vec){
	printf("? ");
	for(auto r:vec) printf("%d ",r);
	printf("\n");
	fflush(stdout);
	return readint();
}

void print(){
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
	printf("\n");
}

int main(){
	n=readint();
	int lst=1;
	for(int k=n;k>=1;k--){
		if(res[k]) continue;
		for(int i=lst+1;i<=n;i++){
			vector<int> vec(0);
			for(int j=1;j<=n;j++){
				if(res[j]||j==k) vec.pb(1);
				else vec.pb(i-lst+1);
			}
			a[i]=query(vec);
			if(!a[i]){
				res[k]=i-1;
				for(int j=lst+1;j<i;j++) res[a[j]]=res[k]-(j-lst);
				break;
			}
		}
		if(!res[k]){
			res[k]=n;
			for(int i=lst+1;i<=n;i++) res[a[i]]=res[k]-(i-lst);
			print();
			return 0;
		}
		lst=res[k]+1;
	}
	print();
	return 0;
}
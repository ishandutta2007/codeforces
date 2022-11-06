#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=100005;
int n,x[Maxn],y[Maxn];
map<pair<int,int>,int> cnt,cc;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
	for (int i=0;i<n;i++){
		int X=x[i]-x[(i+1)%n],Y=y[i]-y[(i+1)%n];
		cnt[mp(X,Y)]++;
		cnt[mp(-X,-Y)]++;
	}
	for (int i=0;i<n;i++){
		int X=x[i]-x[(i+1)%n],Y=y[i]-y[(i+1)%n];
		cnt[mp(X,Y)]-=2;
	}
	for (auto tmp:cnt){
		if (tmp.second!=0){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
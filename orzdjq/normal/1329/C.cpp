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
const int Maxn=3234567;
int h,g;
int a[Maxn];
vector<int> ans;
int n,m;
int Del(int pos){
	if (!a[pos<<1] && !a[pos<<1|1]){
		return pos;
	}
	if (a[pos<<1]>a[pos<<1|1]){
		return Del(pos<<1);
	}
	return Del(pos<<1|1);
}
void F(int pos){
	if (!a[pos<<1] && !a[pos<<1|1]){
		a[pos]=0;
		return;
	}
	if (a[pos<<1]>a[pos<<1|1]){
		a[pos]=a[pos<<1];
		F(pos<<1);
		return;
	}
	a[pos]=a[pos<<1|1];
	F(pos<<1|1);
	return;
}
void Solve(int pos){
	if (!a[pos]) return;
	if (pos>n) return;
	while (Del(pos)>m){
		ans.pb(pos);
		F(pos);
	}
	Solve(pos<<1);
	Solve(pos<<1|1);
}
void mian(){
	ans.clear();
	h=read();g=read();
	n=1<<h;m=1<<g;
	n--;m--;
	for (int i=1;i<=n;i++) a[i]=read();
	
	Solve(1);
	LL S=0; 
	for (int i=1;i<=m;i++) S+=a[i];
	printf("%lld\n",S);
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	for (int i=1;i<=n;i++) a[i]=0;
}
int main(){
	int t;
	t=read();while (t--){
		mian();
	}
}
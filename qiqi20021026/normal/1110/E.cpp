#include<bits/stdc++.h>

using namespace std;

int n,a[120000],b[120000];
map<int,int> cnt;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=n;++i) scanf("%d",b+i);
	for (int i=n;i>=2;--i) a[i]-=a[i-1],b[i]-=b[i-1];
	for (int i=2;i<=n;++i) ++cnt[a[i]];
	for (int i=2;i<=n;++i) if (!(cnt[b[i]]--)){puts("No"); return 0;}
	if (a[1]==b[1]) puts("Yes");
	else puts("No");
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123456;
const int maxp=255;
int n, k;
int mmap[maxp+12];
bool st[maxp+12];
int ans[maxn];
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=0; i<=maxp; i++)
		mmap[i]=i;
	for(int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		int cnt=k-1, p=a;
		while(p>=0&&!st[p]&&cnt>0){
			cnt--;
			p--;
		}
		if(p<0) p++;
		if(st[p]){
			int stt=mmap[p];
			if(a-stt<k) p=stt;
			else p++;
		}
		for(int j=p; j<=a; j++){
			mmap[j]=p;
			st[j]=true;
		}
		ans[i]=mmap[a];
	}
	for(int i=0; i<n; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
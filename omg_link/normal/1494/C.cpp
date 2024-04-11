#include <stdio.h>
#include <algorithm>
#include <set>
#define MN 200000

int n,m,a[MN+5],b[MN+5],t[MN+5];

void solve(){
	int pa=0,pb=0;
	std::set<int> s;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0) pa = i;
	}
	for(int i=1;i<=m;i++){	
		scanf("%d",&b[i]);
		if(b[i]<0) pb = i;
		s.insert(b[i]);
	}
	int ans1 = 0;
	int bans1 = 0;
	for(int i=1;i<=pa;i++){
		if(s.find(a[i])!=s.end()){
			bans1++;
			t[i] = 1;
		}else{
			t[i] = 0;
		}
	}
	for(int i=pb,I=pb,j=pa,cnt=0;i>=1;i--){
		while(j>=1&&a[j]>=b[i]){
			if(t[j]) bans1--;
			cnt++,j--;
		}
		while(I>=1&&b[i]+cnt-1<b[I]) I--;
		ans1 = std::max(ans1,bans1+I-i+1);
	}
	int ans2 = 0;
	int bans2 = 0;
	for(int i=pa+1;i<=n;i++){
		if(s.find(a[i])!=s.end()){
			bans2++;
			t[i] = 1;
		}else{
			t[i] = 0;
		}
	}
	for(int i=pb+1,I=pb+1,j=pa+1,cnt=0;i<=m;i++){
		while(j<=n&&a[j]<=b[i]){
			if(t[j]) bans2--;
			cnt++,j++;
		}
		while(I<=m&&b[i]-cnt+1>b[I]) I++;
		ans2 = std::max(ans2,bans2+i-I+1);
	}
	printf("%d\n",ans1+ans2);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}
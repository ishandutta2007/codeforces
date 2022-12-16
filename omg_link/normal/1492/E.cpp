#include <stdio.h>
#include <map>
#include <vector>
#define MN 250000

int n,m,cnt[MN+5],ans[MN+5];
std::vector<int> a[MN+5];

bool check(){
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<m;j++)
			if(a[i][j]!=ans[j])
				cnt++;
		if(cnt>2) return false;
	}
	return true;
}

bool check(int k){
	ans[k] = -1;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<m;j++)
			if(a[i][j]!=ans[j])
				cnt++;
		if(cnt>3) return false;
		if(cnt==3){
			if(a[i][k]==ans[k]) return false;
			if(ans[k]!=-1) return false;
			ans[k] = a[i][k];
		}
	}
	if(ans[k]==-1) ans[k] = a[0][k];
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		a[i].resize(m);
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	int mcnt = 0;
	int mid = 0;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++)
			if(a[i][j]!=a[0][j])
				cnt[i]++;
		if(cnt[i]>mcnt){
			mcnt = cnt[i];
			mid = i;
		}
	}
	if(mcnt>=5){
		puts("No");
		return 0;
	}
	for(int i=0;i<m;i++)
		ans[i] = a[0][i];
	if(mcnt<=2){
		puts("Yes");
		for(int i=0;i<m;i++)
			printf("%d ",ans[i]);
		puts("");
		return 0;
	}
	if(mcnt==3){
		std::vector<int> p;
		for(int i=0;i<m;i++)
			if(a[0][i]!=a[mid][i])
				p.push_back(i);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				if(i==j) continue;
				ans[p[i]] = a[0][p[i]];
				ans[p[j]] = a[mid][p[j]];
				int k;
				for(k=0;k==i||k==j;k++);
				if(check(p[k])){
					puts("Yes");
					for(int i=0;i<m;i++)
						printf("%d ",ans[i]);
					puts("");
					return 0;
				}
			}
		puts("No");
		return 0;
	}
	if(mcnt==4){
		std::vector<int> p;
		for(int i=0;i<m;i++)
			if(a[0][i]!=a[mid][i])
				p.push_back(i);
		for(int i=0;i<4;i++)
			for(int j=i+1;j<4;j++){
				ans[p[i]] = a[mid][p[i]];
				ans[p[j]] = a[mid][p[j]];
				if(check()){
					puts("Yes");
					for(int i=0;i<m;i++)
						printf("%d ",ans[i]);
					puts("");
					return 0;
				}
				ans[p[i]] = a[0][p[i]];
				ans[p[j]] = a[0][p[j]];
			}
		puts("No");
		return 0;
	}
	return 0;
}
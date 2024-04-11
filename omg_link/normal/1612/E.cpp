#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#define MN 200000

using std::greater;
using std::max;
using std::sort;
using std::vector;

using ll = long long;

int f[MN+5][21];
int sum[MN+5];
vector<int> v[MN+5];

struct Answer{
	int val;
	int cnt;
	
	friend bool operator < (const Answer& lhs,const Answer& rhs){
		return (ll)lhs.val*rhs.cnt < (ll)rhs.val*lhs.cnt;
	}
	
};

Answer ans = {0,1};

int getVal(const vector<int>& v,int cnt){
	int ans = 0;
	for(int x:v){
		if(x>cnt) ans += cnt;
		else ans += x;
	}
	return ans;
}

Answer dp(int cnt){
	memset(f,0,sizeof(f));
	for(int i=1;i<=MN;i++){
		int val = getVal(v[i],cnt);
		for(int j=1;j<=cnt;j++){
			f[i][j] = max(f[i-1][j],f[i-1][j-1]+val);
		}
	}
	return {f[MN][cnt],cnt};
}

void printVector(const vector<int>& v){
	printf("%ld\n",v.size());
	for(size_t i=0;i<v.size();i++)
		printf("%d ",v[i]);
	puts("");
}

void printDpAnswer(){
	int cnt = ans.cnt;
	dp(cnt);
	vector<int> ans;
	int p = cnt;
	for(int i=MN;i>=1;i--){
		int val = getVal(v[i],cnt);
		if(p>0&&f[i-1][p-1]+val==f[i][p]){
			ans.push_back(i);
			p--;
		}
	}
	printVector(ans);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,k;
		scanf("%d%d",&a,&k);
		v[a].push_back(k);
	}
	for(int i=1;i<=20;i++){
		ans = max(ans,dp(i));
	}
	printDpAnswer();
}
#include <cstdio>

typedef long long ll;
const ll mod=1e9+7;
ll ster[1010][1010];
ll psum[1010];
int m, n;

bool same[1010][1010];
char str[1010];

bool check[1010];
int dfs(int now){
	int ans=1;
	for(int i=0; i<m; i++)
		if(!check[i] && same[now][i]){
			check[i]=true;
			ans+=dfs(i);
		}
	return ans;
}

int main(){
	scanf("%d %d", &m, &n);

	ster[1][1]=1, psum[1]=1;
	for(int i=2; i<=m; i++)
		for(int j=1; j<=m; j++){
			ster[i][j]=(j*ster[i-1][j]%mod + ster[i-1][j-1])%mod;
			psum[i]=(psum[i]+ster[i][j])%mod;
		}

	for(int i=0; i<m; i++)
		for(int j=0; j<m; j++)
			same[i][j]=true;

    for(int i=0; i<n; i++){
		scanf("%s", str);
		for(int j=0; j<m; j++)
			for(int k=0; k<m; k++)
				if(str[j]!=str[k]) same[j][k]=same[k][j]=false;
	}

	ll ans=1;
    for(int i=0; i<m; i++){
		if(!check[i]){
			check[i]=true;
			ans=ans*psum[dfs(i)]%mod;
		}
    }
    printf("%I64d", ans);
	return 0;
}
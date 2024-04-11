#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

long long dp[256][256];
long long f(int p,int q){
	if(p==0){return 0;}
	if(q==0){return 1;}
	if(dp[p][q]!=-1){return dp[p][q];}
	dp[p][q]=(modular_inverse(2)*(f(p-1,q)+f(p,q-1)))%mod;
	return dp[p][q];
}

int main(){
	for(int i=0;i<256;i++){
		for(int j=0;j<256;j++){dp[i][j]=-1;}
	}
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
	cin >> n;
	vector<vector<int>> d(n,vector<int>(n,mod));
	for(int i=1;i<n;i++){
		int p,q;
		cin >> p >> q;
		p--;q--;
		d[p][q]=1;
		d[q][p]=1;
	}
	for(int i=0;i<n;i++){d[i][i]=0;}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){cout << d[i][j] << ' ';}
	// 	cout << '\n';
	// }
	long long res=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int dis=d[i][j];
			//cout << d[i][j] << ',';
			long long cnt=0;
			for(int k=0;k<n;k++){
				if(d[k][i]-d[k][j]>=dis){cnt++;cnt%=mod;}
				else if(d[k][j]-d[k][i]>=dis){continue;}
				else{
					int v=(d[k][i]-d[k][j]);
					//cout << v << '\n';
					cnt+=f((dis+v)/2,(dis-v)/2);cnt%=mod;
				}
			}
			//cout << i << ' ' << j << ' ' << cnt << '\n';
			cnt*=modular_inverse(n);cnt%=mod;
			//cout << cnt << '\n';
			res+=cnt;res%=mod;
		}
	}
	cout << res << '\n';
  return 0;
}
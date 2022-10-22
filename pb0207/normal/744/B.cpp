#include<bits/stdc++.h>
#define INF 2147483640
#define eps 1e-9
#define N 500005
#define MOD 998244353
using namespace std;
int n,m,k,u,v,ans,cnt[N],f[N];
bool vis[N];
vector<int> G[N];
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++) f[i] = INF;
	for(int i = 0;i <= log2(n)+1;i++)
	 for(int odd = 0;odd <= 1;odd ++)
	 {
	 	int sum = 0;
	 	for(int j = 0;j < n;j++)
	 	 if(((j&(1<<i))>>i) == odd) sum++;
        if(sum == n || !sum) continue;
        cout<<sum<<endl;
        for(int j = 0;j < n;j++)
         if(((j&(1<<i))>>i) == odd) cout<<j+1<<" ";
        cout<<endl;
        fflush(stdout);
        for(int j = 0;j < n;j++)
        {
            int temp;
            cin>>temp;
            if(((j&(1<<i))>>i) == (odd^1)) f[j] = min(f[j],temp);
        }
	 }
	 cout<<"-1"<<endl;
	 for(int i = 0;i < n;i++) cout<<f[i]<<" ";
	 fflush(stdout);
}
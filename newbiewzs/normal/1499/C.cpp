#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define int long long
using namespace std;
typedef long long ll;
const int N=1e5+55;
int T,a[N],n;
signed main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=(a[1]*n+a[2]*n);
		int maxx=a[1];
		int minn=a[2];
		int x=1,y=1,pre=a[1]+a[2];
		for(int i=3;i<=n;i++){
			if(i&1)x++,maxx=min(maxx,a[i]);
			else y++,minn=min(minn,a[i]);
			pre+=a[i];
			ans=min(ans,(n-x+1)*maxx+(n-y+1)*minn+pre-maxx-minn);
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
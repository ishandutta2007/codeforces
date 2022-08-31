#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,k,ans;
ll a[100005],b[100005];

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i];
	ll now=0,lst=-1,cnt=0;
	for(int i=1;i<=m;i++){
		if(lst<0) lst=(a[i]-now-1)/k,cnt=1;
		else if((a[i]-now-1)/k!=lst){
			ans++;
			now+=cnt;
			lst=(a[i]-now-1)/k;
			cnt=1;
		}
		else cnt++;
	}
	cout<<ans+1<<endl;
	return 0;
}
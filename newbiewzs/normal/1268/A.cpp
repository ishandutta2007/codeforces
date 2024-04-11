#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=4e5+55;
int T,n,x;
bool pd[N];
char a[N];
int ans[N],top,maxx[N],tmp[N];
int check(){
	for(int i=1;i<=n;i++){if(maxx[i]>tmp[i]){return 0;}if(maxx[i]<tmp[i]){return 1;}}
	return 0;
}
void solve(){
	n=read();x=read();
	scanf("%s",a+1);
	for(int i=n+1;i<=2*n;i++)a[i]='0';
	for(int j=1;j<=n;j++){
		maxx[j]=a[(j-1)%x+1]-'0';
		tmp[j]=a[j]-'0';
	}
	if(!check()){
		for(int i=1;i<=n;i++)ans[i]=maxx[(i-1)%x+1];
	}
	else{
		for(int k=1;k<=x;k++)ans[k]=a[k]-'0';
		ans[x]++;
		for(int i=x;i>=1;i--){
			if(ans[i]>9)ans[i-1]+=ans[i]/10,ans[i]%=10;
		}
		for(int i=1;i<=n;i++)ans[i]=ans[(i-1)%x+1];
	}
	cout<<n<<endl;
	for(int i=1;i<=n;i++)cout<<ans[i];
}
int main(){
	//cin>>T;
	T=1;
	while(T--){
		solve();
	}
	return 0;
}
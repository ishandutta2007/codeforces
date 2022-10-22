#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back()
#define all(a) a.begin(),a.end()
using namespace std;
void voi(){
	int n,a[405];
	scanf("%d",&n);n=(n<<2);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[1]==a[2]&&a[n-1]==a[n]){
		int t=a[1]*a[n];
		for(int i=2;i<=(n>>2);i++){
			if(a[(i<<1)]!=a[(i<<1)-1]||a[n-(i<<1)+2]!=a[n-(i<<1)+1]
				||a[(i<<1)]*a[n-(i<<1)+2]!=t){
				cout<<"NO\n";return ;
			}
		}
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)voi();
	return 0;
}
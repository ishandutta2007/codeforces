#include <bits/stdc++.h>
using namespace std;
inline void out(int X){
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) out(X/10);
	putchar(X%10+'0');
}
vector <int> a;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	if(m<n-1||m>n-1+(n-3)*(n-2)/2){
		out(-1);return 0;
	}
	for(int i=1;i<=n;i++){
		if(i!=k){
			a.push_back(i);
			out(i);putchar(' ');out(k);
			putchar('\n');
		}
	}
	m-=n-1;
	for(int i=0;i<a.size()-2;i++){
		for(int j=i+1;j<a.size()-1;j++){
			if(m==0)return 0;
			m--;
			out(a[i]);putchar(' ');out(a[j]);
			putchar('\n');
		}
	}
	return 0;
}
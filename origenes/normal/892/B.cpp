#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int maxn=1234567;
ll L[maxn], n, d[maxn], tot, cur;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++)
		scanf("%d", &L[i]);
	for(int i=n; i>0; i--){
		d[i-1]++;
		if(i-L[i]>=1) d[i-L[i]-1]--;
		else d[0]--;
	}
	for(int i=n; i>=1; i--){
		cur+=d[i];
		if(cur<=0) tot++;
	}
	cout<<tot<<endl;
	return 0;
}
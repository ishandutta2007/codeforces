#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int id,zhi;
}a[200005];
bool cmp(node x,node y){
	return x.zhi<y.zhi;
}
int b[200005];
bool check(int x){
	int q=1;
	FOR(i,1,n){
		if(i!=x)b[q++]=a[i].zhi;
	}
	int s=b[2]-b[1];
	for(int i=3;i<n;i++){
		if(b[i]-b[i-1]!=s)RE 0;
	}
	RE 1;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i].zhi,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	if(n==2||n==3){
		cout<<1;return 0;
	}
	int f=1,s;
	if(check(1)){
		cout<<a[1].id;RE 0;
	}
	if(check(2)){
		cout<<a[2].id;RE 0;
	}
	if(check(n)){
		cout<<a[n].id;RE 0;
	}
	s=a[2].zhi-a[1].zhi;
	int ans;
	for(int i=3;i<=n;i++){
		if(a[i].zhi-a[i-1].zhi!=s){
			if(a[i+1].zhi-a[i-1].zhi!=s||!f){
				cout<<-1;RE 0;
			}else f=0,ans=a[i].id,i++;
		}
	}
	cout<<ans;
	RE 0;
}
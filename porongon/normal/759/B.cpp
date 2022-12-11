#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
int t[100005];
int f[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",t+i);
	f[0]=0;
	fore(i,1,n+1){
		f[i]=f[i-1]+20;
		int k=lower_bound(t,t+n,t[i-1]-89)-t;
		f[i]=min(f[i],f[k]+50);
		k=lower_bound(t,t+n,t[i-1]-1439)-t;
		f[i]=min(f[i],f[k]+120);
	}
	fore(i,1,n+1){
		printf("%d\n",f[i]-f[i-1]);
	}
	return 0;
}
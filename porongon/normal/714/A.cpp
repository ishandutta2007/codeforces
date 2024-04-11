#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;


int main(){
	ll l1,r1,l2,r2,k,l,r;
	cin>>l1>>r1>>l2>>r2>>k;
	l=max(l1,l2);
	r=min(r1,r2);
	if(l>r){puts("0");return 0;}
	ll s=r-l+1;
	if(k>=l&&k<=r)s--;
	cout<<s<<endl;
	return 0;
}
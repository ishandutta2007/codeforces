#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

ll k;

int main(){
	cin>>k;
	if(k<=2)cout<<"-1"<<endl;
	else if(k%2){
		ll m=k/2+1,n=k/2;
		cout<<2*m*n<<' '<<m*m+n*n<<endl;
	}
	else {
		ll m=k/2,n=1;
		cout<<m*m-n*n<<' '<<m*m+n*n<<endl;
	}
	return 0;
}
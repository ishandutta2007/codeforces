#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int t;
	cin >> t;
	while(t>0){
		t--;
	  int n,k;
	  cin >> n >> k;
	  long long res=0;
	  if(k==0){res=1;}
	  else if(n%2==0){
	    long long sk=power(power(2,n),k-1);
	    long long kh=(power(2,n-1)+(mod-1))%mod;
	    kh*=modular_inverse(power(2,n));kh%=mod;
	    if(kh==1){res=(kh*k)%mod;}
	    else{
	      res=sk;
	      res*=(power(kh,k)+mod-1);res%=mod;
	      res*=modular_inverse(kh+mod-1);res%=mod;
	    }
	    res+=power((power(2,n-1)+(mod-1))%mod,k);
	    res%=mod;
	  }
	  else{
	    res=power((power(2,n-1)+1)%mod,k);
	  }
	  cout << res << '\n';
	}
  return 0;
}
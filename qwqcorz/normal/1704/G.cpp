#include<bits/stdc++.h>
#define ll long long
#define int ll
#define poly vector<int>
using namespace std;
const int mod=998244353;

int power(int a,int b) {
	int ret=1;
	for (;b;b/=2) {
		if (b&1) {
			ret=1LL*ret*a%mod;
		}
		a=1LL*a*a%mod;
	}
	return ret;
}
int inv(int a) {
	if (a>=mod) {
		a%=mod;
	}
	return power(a,mod-2);
}
int lim,l;
vector<int>rev;
void ntt(poly &a,int type) {
	for (int i=0;i<lim;i++) {
		if (rev[i]>i) {
			swap(a[i],a[rev[i]]);
		}
	}
	for (int mid=1;mid<lim;mid*=2) {
		int Wn=power(type>0?3:inv(3),(mod-1)/mid/2);
		for (int len=mid*2,k=0;k<lim;k+=len) {
			int w=1;
			for (int i=k;i<k+mid;i++,w=1LL*w*Wn%mod) {
				int x=a[i],y=1LL*w*a[i+mid]%mod;
				a[i]=(x+y)%mod;
				a[i+mid]=(x-y+mod)%mod;
			}
		}
	}
	if (type<0) {
		int invn=inv(lim);
		for (int i=0;i<lim;i++) {
			a[i]=1LL*a[i]*invn%mod;
		}
	}
}
poly operator *(poly a,poly b) {
	if (a.empty()) a=poly({0});
	if (b.empty()) b=poly({0});
	int n=a.size(),m=b.size();
	for (lim=1,l=0;lim<=n+m;l++) lim*=2;
	a.resize(lim),b.resize(lim),rev.resize(lim);
	for (int i=0;i<lim;i++) {
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	}
	ntt(a,1),ntt(b,1);
	for (int i=0;i<lim;i++) {
		a[i]=1LL*a[i]*b[i]%mod;
	}
	ntt(a,-1);
	a.resize(n+m-1);
	return a;
}
bool flag=0;
void work() {
	int n,m;
	cin>>n;
	poly a(n),F(n);
	for (int i=0;i<n;i++) {
		cin>>a[i];
		if (i>=2) {
			F[i]=(a[i-2]+2*a[i-1]+a[i])%mod;
		}
	}
	cin>>m;
	poly b(m),G(m);
	for (int i=0;i<m;i++) {
		cin>>b[i];
		if (i>=2) {
			G[i]=(b[i-2]+2*b[i-1]+b[i])%mod;
		}
	}
	F.erase(F.begin(),F.begin()+2);
	G.erase(G.begin(),G.begin()+2);
	reverse(G.begin(),G.end());
	poly H=F*G;
	reverse(G.begin(),G.end());
	int sum=0;
	vector<int>S((int)F.size()+1);
	for (int i=0;i<(int)F.size();i++) {
		S[i]=(F[i]*F[i]+F[i])%mod;
	}
	for (int i=(int)F.size()-1;i>=0;i--) {
		S[i]+=S[i+1];
		S[i]%=mod;
	}
	for (int i:G) {
		sum+=i*i-i;
		sum%=mod;
	}
	for (int i=0;i+m-1<n;i++) {
		if (i+(int)G.size()-1<0||((sum+S[i]-S[i+m-2]-2*H[i+(int)G.size()-1])%mod+mod)%mod==0) {
			int t0=b[0]-a[i],t1=b[1]-a[i+1];
			int A1=t0,A2=t1+t0,AA=(A1%2+2)%2;
			int n1=i+1,n2=i+1;
			if (n1%2==0) {
				n1--;
			}
			if (n2%2==1) {
				n2--;
			}
			int tot1=n1/2+1,tot2=n2/2+1;
		  int l=max(0LL,-A2),r=min(tot1,tot2-A2),A,B,C,x_;
		  if (l%2!=AA) {
		  	l++;
		  }
		  if (r%2!=AA) {
		  	r--;
		  }
		  if (l>r) {
		  	continue;
		  }
			auto f=[&](int x) {
				return A*x*x+B*x+C;
			};
		  
		  A=2,B=2*A2-n2-1,C=A2*A2-n2*A2-A2;
		  int mn=min(f(l),f(r));
		  x_=-B/(2*A);
		  for (int i=x_-3;i<=x_+3;i++) {
		  	if (i%2==AA&&l<=i&&i<=r) {
		  		mn=min(mn,f(i));
		  	}
		  }
			
		  A=-2,B=n1-2*A2+2,C=A2-A2*A2;
		  int mx=max(f(l),f(r));
		  x_=-B/(2*A);
		  for (int i=x_-3;i<=x_+3;i++) {
		  	if (i%2==AA&&l<=i&&i<=r) {
		  		mx=max(mx,f(i));
		  	}
		  }
		  if (mn<=A1&&A1<=mx) {
		  	int x=-1;
		  	for (int i=l;i<=r;i++) {
		  		if (i%2!=AA) {
						continue;
					}
					A=2,B=2*A2-n2-1,C=A2*A2-n2*A2-A2;
					if (f(i)>A1) {
		  			continue;
		  		}
					A=-2,B=n1-2*A2+2,C=A2-A2*A2;
					if (f(i)<A1) {
		  			continue;
		  		}
		  		x=i;
		  		break;
		  	}
				A=-2,B=n1-2*A2+2,C=A2-A2*A2;
		  	int y=x+A2,k=f(x)-A1;
		  	vector<int>a(x+1),b(y+1);
		  	for (int i=0;i<x;i++) {
		  		a[i]=n1-i*2;
		  	}
		  	for (int i=0;i<y;i++) {
		  		b[i]=-i*2;
		  	}
		  	a[x]=-1;
				for (int i=x-1;i>=0;i--) {
		  		int tmp=min(k,a[i]-a[i+1]-2);
		  		k-=tmp,a[i]-=tmp;
		  	}
		  	b[y]=-n2-2;
				for (int i=y-1;i>=0;i--) {
		  		int tmp=min(k,b[i]-b[i+1]-2);
		  		k-=tmp,b[i]-=tmp;
		  	}
		  	vector<int>ans;
		  	for (int j=0;j<x;j++) {
		  		ans.push_back(i+1-a[j]);
		  	}
		  	for (int j=0;j<y;j++) {
		  		ans.push_back(i+1+b[j]);
		  	}
		  	for (int j=2;j<m;j++) {
		  		if (F[i+j-2]+1==G[j-2]) {
		  			ans.push_back(i+j);
		  		}
		  	}
		  	sort(ans.begin(),ans.end());
		  	cout<<ans.size()<<"\n";
		  	for (int i:ans) {
		  		cout<<i+1<<" ";
		  	}
		  	cout<<"\n";
		  	
		  	return;
		  }
		}
	}
	cout<<"-1\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
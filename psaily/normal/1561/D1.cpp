#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int N=4e6+5;

int n,mod;
int f[N],sum[N];
int tot;

void add(int &a,int b) {a+=b; if (a>=mod) a-=mod;}
void sub(int &a,int b) {a-=b; if (a<0) a+=mod;}

int main() {
	scanf("%d%d",&n,&mod);
	
	f[1]=1;
	rep(i,1,n+1) {
		add(sum[i],sum[i-1]);
		add(f[i],sum[i]);
		add(sum[i+1],f[i]),sub(sum[n+1],f[i]);
		
		for (int j=2;j*i<=n;j++) {
			add(sum[j*i],f[i]);
			if (j*(i+1)<=n) sub(sum[j*(i+1)],f[i]);
		}
	}
	
	printf("%d\n",f[n]);
	return 0;	
}
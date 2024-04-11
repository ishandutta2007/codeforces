#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
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
 
const int mod=998244353;
const int N=3e5+5;

int sum,n,T;
int pw[15];

int main() {
	pw[0]=1;
	rep(i,1,10) pw[i]=pw[i-1]*10;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&sum,&n);
		while (n) {
			if (n==1) {printf("%d\n",sum); break;}
			int bit=0;
			per(i,10,0) if (pw[i]<=sum) {bit=i; break;}
			while (sum-pw[bit]<n-1) bit--;
			printf("%d ",pw[bit]);
			sum-=pw[bit],n--;
		}
	}
	return 0;	
}
#include <bits/stdc++.h>
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
  
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;

int n,T;
bool mark[1015];
struct node {int a,b,c;}t[1015];

int main() {
	scanf("%d",&T);
	for (int i=0,cnt=0;i<=1000;i+=3,cnt++) {
		mark[i]=1;
		t[i]=(node){cnt,0,0};
	}
	for (int i=0;i<=1000;i++) {
		if (mark[i]&&!mark[i+5]) {
			mark[i+5]=1;
			node e=t[i];
			t[i+5]=(node) {e.a,e.b+1,e.c};
		}
	}
	for (int i=0;i<=1000;i++) {
		if (mark[i]&&!mark[i+7]) {
			mark[i+7]=1;
			node e=t[i];
			t[i+7]=(node) {e.a,e.b,e.c+1};
		}
	}
	while (T--) {
		scanf("%d",&n);
		if (!mark[n]) puts("-1");
		else printf("%d %d %d\n",t[n].a,t[n].b,t[n].c);
	}
	return 0;
}
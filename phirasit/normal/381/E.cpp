#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MX_N 1000010
#define mp make_pair
#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
char str[MX_N];
int tree[4*MX_N][3];
pii val[4*MX_N];

int mn(int a,int b) {
	if(a < b) return a;
	return b;
}
void set(int node,int a,int b) {
	if(a < b) {
		int m = (a+b)/2;
		set(2*node,a,m);
		set(2*node+1,m+1,b);
		pii x = val[2*node],y = val[2*node+1];
		tree[node][2] = tree[2*node][2] + tree[2*node+1][2] + 2*mn(x.B,y.A);
		if(y.A > x.B) x.A += y.A - x.B;
		else y.B += x.B - y.A;
		val[node] = mp(x.A,y.B);
	}else {
		int x = (str[a] == ')');
		int y = (str[a] == '(');
		val[node] = mp(x,y);
		tree[node][2] = 0;
	}	
	tree[node][0] = a;
	tree[node][1] = b;
}
piii query(int node,int a,int b) {
	if(a <= tree[node][0] && tree[node][1] <= b)
		return mp(tree[node][2],val[node]);
	if(a > tree[node][1] || b < tree[node][0])
		return mp(0,mp(0,0));
	piii x = query(2*node,a,b);
	piii y = query(2*node+1,a,b);
	if(x.B.B > y.B.A) y.B.B += x.B.B-y.B.A;
	if(x.B.B < y.B.A) x.B.A += y.B.A-x.B.B;
	return mp(x.A + y.A + 2*mn(x.B.B,y.B.A),mp(x.B.A,y.B.B));
}
int main() {
	int i,j,m;
	scanf("%s",str);
	set(1,0,strlen(str)-1);
	scanf("%d",&m);
	while(m--) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query(1,a-1,b-1).A);
	}
	return 0;
}
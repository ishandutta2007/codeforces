#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%.12f",n)
#define psp printf(" ")
#define endc printf("\n")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

//const int maxn = 2e5 + 7; 
//const int md = 1e9 + 7;

int main() {
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	int a = abs(x2 - x1), b = abs(y2 - y1);
	a = max(2, a+1); b = max(2, b+1);	
	cout<<(a+b+a+b)<<endl;
}
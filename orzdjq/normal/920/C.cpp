#include<bits\stdc++.h>
using namespace std;
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
const int Maxn=200005;
int a[Maxn];
char s[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%s",s);
	vector<int> now;
	int st=1;
	for (int i=0;i<n-1;i++){
		now.push_back(a[i+1]);
		if (s[i]=='0'){
			sort(now.begin(),now.end());
			if (now[0]!=st){
				printf("NO\n");
				return 0;
			}
			for (int j=1;j<now.size();j++){
				if (now[j]-now[j-1]!=1){
					printf("NO\n");
					return 0;
				}
			}
			st=now.back()+1;
			now.clear();
		}
	}
	printf("YES\n");
	return 0;
}
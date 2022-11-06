#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

char s[200010];
queue<int> wait[2];
int nxt[200010];
int sp[200010], sn;

int main()
{
	scanf("%s", s+1);
	for(int i=1; s[i]; ++i){
		if(s[i] == '0'){
			if(wait[0].size()){
				nxt[wait[0].front()]=i;
				wait[0].pop();
				wait[1].push(i);
			} else {
				sp[sn++] = i;
				wait[1].push(i);
			}
		} else if(s[i] == '1'){
			if(wait[1].size()){
				nxt[wait[1].front()]=i;
				wait[1].pop();
				wait[0].push(i);
			} else {
				puts("-1");
				return 0;
			}
		}
	}
	if(wait[0].size()){
		puts("-1");
		return 0;
	}
	printf("%d\n", sn);
	for(int i=0; i<sn; ++i){
		int c=0;
		for(int j=sp[i]; j; j=nxt[j]) ++c;
		printf("%d ", c);
		for(int j=sp[i]; j; j=nxt[j]) printf("%d ", j);
		putchar(10);
	}
	return 0;
}
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
int ans;

stack<int> speed, overtake;

int main()
{
	speed.emplace(1e9);
	overtake.emplace(1);
	int nows = 0;
	int n; read(n);
	for(;n--;){
		int type, sp=0;
		read(type);
		if(type==1 || type==3) read(sp);
		if(type == 1){
			while(speed.top() < sp){
				++ans; speed.pop();
			}
			nows = sp;
		}
		if(type == 2){
			while(overtake.top() == 0){
				++ans; overtake.pop();
			}
		}
		if(type == 3){
			if(nows > sp){
				++ans;
			} else speed.push(sp);
		}
		if(type == 4){
			overtake.push(1);
		}
		if(type == 5){
			speed.push(1e9);
		}
		if(type == 6){
			overtake.push(0);
		}
	}
	printf("%d\n", ans);
	return 0;
}
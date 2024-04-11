#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
std::multiset<P> big,small;
int now = 0;LL sm1 = 0,sm2 = 0;int smb = 0;

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int n;scanf("%d",&n);
	FOR(c,1,n){
		int tp,d;scanf("%d%d",&tp,&d);
		if(d > 0){
			now += tp;
			if(small.empty() || d >= small.rbegin()->fi){
				big.insert(MP(d,tp));sm1 += d;smb += tp;
			}
			else{
				small.insert(MP(d,tp));sm2 += d;
			} 
		}
		else{
			now -= tp;d = -d;
			if(big.count(MP(d,tp))) big.erase(big.find(MP(d,tp))),sm1 -= d,smb -= tp;
			else small.erase(small.find(MP(d,tp))),sm2 -= d;
		}
		while(big.size() > now){
			small.insert(*big.begin());
			sm1 -= big.begin()->fi;
			sm2 += big.begin()->fi;
			smb -= big.begin()->se;
			big.erase(big.begin());
		}
		while(big.size() < now){
			big.insert(*small.rbegin());
			sm1 += small.rbegin()->fi;
			sm2 -= small.rbegin()->fi;
			smb += small.rbegin()->se;
			small.erase((--small.end()));
		}
		if(!big.empty() && !small.empty()){
			assert(big.begin()->fi >= small.rbegin()->fi);
		}
		if(smb != now || now == 0){
			printf("%lld\n",sm1*2+sm2);
		}
		else{
			if(small.empty()){
				printf("%lld\n",sm1*2+sm2-big.begin()->fi);
			}
			else{
				printf("%lld\n",sm1*2+sm2-big.begin()->fi+small.rbegin()->fi);
			}
		}
	}
	return 0;
}
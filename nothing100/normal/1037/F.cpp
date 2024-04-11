#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define LL long long
#define mo 1000000007
using namespace std;
int n,k,a[1000010];
LL res[1000010],ans;
deque<pair<int,int> > ma;
vector<pair<int,int> > q[1000010];
void ins(int x){
	while (!ma.empty()&&ma.back().fi<a[x]) ma.pop_back();
	ma.push_back(mp(a[x],x));
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=n-1;i>n-k;i--) ins(i);
	for (int i=n-k;i>=0;i--){
		ins(i);
		while (ma.front().se>i+k-1) ma.pop_front();
		pair<int,int> tmp;
		tmp.fi=ma.front().fi;
		tmp.se=1;
		while (q[i%(k-1)].size()>0&&q[i%(k-1)].back().fi<=tmp.fi){
			res[i%(k-1)]-=1LL*q[i%(k-1)].back().fi*q[i%(k-1)].back().se;
			res[i%(k-1)]%=mo;
			res[i%(k-1)]+=mo;
			res[i%(k-1)]%=mo;
			tmp.se+=q[i%(k-1)].back().se;
			q[i%(k-1)].pop_back();
		}
		q[i%(k-1)].push_back(tmp);
		res[i%(k-1)]+=1LL*tmp.fi*tmp.se;
		res[i%(k-1)]%=mo;
		ans+=res[i%(k-1)];
		ans%=mo;
	}
	printf("%lld\n",ans);
}
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define pb push_back

int n,t;
int a[222222];
int l[222222];
int r[222222];
ll res[222222];
ll sum;
int x[1111111];

vector<pair<pii,int> > w;

int main(){ 
	cin>>n>>t;
	REP(i,n) scanf("%d",a+i);
	REP(i,t) scanf("%d %d",l+i,r+i),r[i]--,l[i]--,w.pb(make_pair(pii(l[i]/500,r[i]),i));

	SORT(w);
	int start = 0;
	int end   = -1;
	for(int i=0;i<t;){
		int j=i;
		while(j<t && w[j].first.first==w[i].first.first) j++;
		FOR(k,i,j){
			int L = l[w[k].second];
			int R = r[w[k].second];
			while(start>L){
				start --;
				sum -= a[start] * ll(x[a[start]]) * x[a[start]];
				x[a[start]]++;
				sum += a[start] * ll(x[a[start]]) * x[a[start]];
			}
			while(start<L){
				sum -= a[start] * ll(x[a[start]]) * x[a[start]];
				x[a[start]]--;
				sum += a[start] * ll(x[a[start]]) * x[a[start]];
				start ++;
			}
			
			while(end<R){
				end ++;
				sum -= a[end] * ll(x[a[end]]) * x[a[end]];
				x[a[end]]++;
				sum += a[end] * ll(x[a[end]]) * x[a[end]];
			}
			while(end>R){
				sum -= a[end] * ll(x[a[end]]) * x[a[end]];
				x[a[end]]--;
				sum += a[end] * ll(x[a[end]]) * x[a[end]];
				end --;				
			}


			res[w[k].second] = sum;
		}

		i=j;
	}
	REP(i,t) printf("%I64d\n",res[i]);
	return 0;
}
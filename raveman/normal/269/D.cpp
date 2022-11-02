#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

typedef pair<int,pii> p3;

int n,t;
p3  p[111111];
int r[111111];

map<int,int> w;

bool inter(int v1,int v2){
	if(max(p[v1].second.first,p[v2].second.first) < min(p[v1].second.second,p[v2].second.second))
		if(p[v2].first < p[v1].first)
			return 1;
	return 0;
}

bool good(int v1,int v2,int v3){
	if(inter(v1,v2)){
		if(v3!=-1) if(inter(v1,v3) && inter(v3,v2))
			return 0;
		return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	const int inf = 1011111111;

	cin>>n>>t;
	REP(i,n) scanf("%d %d %d",&p[i].first,&p[i].second.first,&p[i].second.second);

	p[n]=p3(t,pii(-inf,inf));
	p[n+1]=p3(0,pii(-inf,inf));
	n+=2;
	sort(p,p+n);
	reverse(p,p+n);
	w[-inf] = 0;
	r[0] = 2*inf;
	FOR(i,1,n){
		int from = p[i].second.first;
		int to = p[i].second.second;
		//cout<<"process "<<i<<endl;
		//step1
		map<int,int>::iterator it = w.lower_bound(from+1),it2,it3;
		it2=it;
		it--;
		int res = 0;
		while(1){
			int currfrom = it->first;
			int currto = (it2==w.end() ? inf : it2->first);

			int seg = it->second;

			int segp = -1;
			if(it!=w.begin()){
				it3=it;
				--it3;
				segp=(it3->second);
			}
			int segn = -1;
			//cout<<it<<' '<<it2<<endl;
			if(it2!=w.end())
				segn = it2->second;
			//cout<<"check "<<seg<<endl;
			if(good(seg,i,segn) && good(seg,i,segp)){
				int tt = min(r[seg], min(p[i].second.second,p[seg].second.second)-max(p[i].second.first,p[seg].second.first));
		//		cout<<" for "<<seg <<" = "<<tt<<" " <<r[seg]<<" "<<min(p[i].second.second,p[seg].second.second)<<" "<<max(p[i].second.first,p[seg].second.first)<<endl;
			///	cout<<segn<<" "<<good(seg,i,segn)<<endl;
				//cout<<segp<<" "<<good(seg,i,segp)<<endl;
				//cout<<segn<<' '<<segp<<endl;
				res=max(res, tt);
			}

			if(it2==w.end() || it2->first>=to) break;
			it=it2;
			++it2;
		}
		r[i]=res;
		
		//step2
		it = w.lower_bound(from);
		if(it!=w.begin()){
			it2 = it;
			int toto = (it2==w.end()?inf:it2->first);
			--it;
			//cout<<toto<<endl;
			if(toto>to)
				w[to] = it->second;
		}


		while(1){
			it = w.lower_bound(from);
			if(it==w.end()) break;
			int currfrom = it->first;
			if(to<=currfrom)break;
			int seg = it->second;
			it2=it;
			++it2;
			int currto = (it2==w.end() ? inf : it2->first);
			w.erase(it);

			if(currto>to)
				w[to] = seg;			
		}
		w[from]=i;
		/*
		cout<<"end it"<<endl;puts("");
		for(map<int,int>::iterator it = w.begin();it!=w.end();it++)
			cout<<it->first<< " -> "<<it->second<<endl;
		puts("");*/
	}
	cout<<r[n-1]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[111111];
int p[111111];
int b[111111];

const int inf = 1011111111;

int r1[111111];
int r2[111111];

typedef pair<pii,pii> p4;
vector<p4> v_up;
vector<p4> v_down;

void addUpSh(int sh1,int sh2,int start){
	if(sh1>sh2) return;
	//cout<<"add Up "<<sh1<<' '<<sh2<<' '<<start<<endl;
	v_up.pb(p4(pii(sh1-start,sh1),pii(sh2,start)));
}

void addDownSh(int sh1,int sh2,int start){
	if(sh1>sh2) return;
	//cout<<"add Down "<<sh1<<' '<<sh2<<' '<<start<<endl;
	v_down.pb(p4(pii(sh1+start, sh1),pii(sh2,start)));
}

set<int> t;

void parseUp(){
	t.clear();
	REP(i,n) t.insert(i);
	SORT(v_up);
	for(int i=int(v_up.size())-1;i>=0;i--){
		int start = v_up[i].first.first;
		int r_start = v_up[i].first.second;
		int sh2 = v_up[i].second.first;
		int val = v_up[i].second.second;
		//cout<<start
		while(1){
			set<int>::iterator it = t.lower_bound(r_start);
			if(it==t.end()) break;
			int pos = *it;
			if(pos>sh2) break;
			t.erase(pos);
			r2[pos] = min(r2[pos], val + pos - r_start);
		}
	}
}

void parseDown(){
	t.clear();
	REP(i,n) t.insert(i);
	SORT(v_down);
	REP(i,v_down.size()){
		int start = v_down[i].first.first;
		int r_start = v_down[i].first.second;
		int sh2 = v_down[i].second.first;
		int val = v_down[i].second.second;

		//cout<<"pd "<<r_start<<' '<<sh2<<' '<<val<<endl;

		while(1){
			set<int>::iterator it = t.lower_bound(sh2+1);
			if(it==t.begin()) break;
			it--;
			int pos = *it;
			if(pos<r_start) break;
			t.erase(pos);
			//cout<<"use "<<pos<<' '<<start-pos+r_start<<endl;
			r1[pos] = min(r1[pos], val - pos + r_start);
		}
	}
}

int c[111111];
int go(int pos){
	REP(i,n) c[(i-pos+n)%n] = b[i];
	int res = inf;
	REP(i,n)REP(j,n)if(a[i]==c[j])res=min(res,abs(i-j));
	return res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	start:
	REP(i,n) scanf("%d",a+i);
	REP(i,n) scanf("%d",b+i);
	//n=10;
	//REP(i,n)a[i]=i+1,b[i]=i+1;
	//random_shuffle(a,a+n);
	//random_shuffle(b,b+n);
	//REP(i,n) cout<<a[i]<<' ';puts("");
	//REP(i,n) cout<<b[i]<<' ';puts("");

	REP(i,n) a[i]--,b[i]--,p[a[i]]=i;
	REP(i,n) r1[i]=r2[i]=inf;
	v_up.clear();v_down.clear();
	REP(i,n){
		//cout<<"parse "<<i<<endl;
		int pos = p[b[i]];
		if(pos>=i){
			int sh1 = pos - i;
			int sh2 = (n-1) - i;
			addUpSh(sh1, sh2, 0);
			addDownSh(sh2+1, n-1, pos);
			addDownSh(0, sh1 -1, pos-i);
		}else{
			addUpSh(0, n-1-i, i-pos);
			addDownSh(n-1-i+1, n-i+pos, pos);
			addUpSh(n-i+pos+1, n-1, 1);
		}
	}

	parseUp();
	parseDown();
	//bool good = 1;
	REP(i,n){
		printf("%d\n",min(r1[(n-i)%n],r2[(n-i)%n]));
		//if(min(r1[(n-i)%n],r2[(n-i)%n])!=go(i)) good=0;
	}
	//if(good) goto start;

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
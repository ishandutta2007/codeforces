#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a) 
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back
#define SORT(a)			sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n,m,k;
map<string,int> iid;
int t[111];
int start[4],end[4];

struct Dude{
	int subj;
	int day;
	int t;
	int money;
	Dude(){
		string s;
		cin>>s;
		subj = -1;
		if(iid.count(s)) subj = iid[s];
		cin>>day;
		int x,y;
		scanf("%d:%d",&x,&y);
		t = x * 60 + y;
		cin>>money;
	}
	int id;
	bool operator<(const Dude&s)const{
		return 24*60*day + t < 24*60*s.day +s.t;
	}
};

bool busy[100000];

void mark_busy(int from,int to){
	while(from>to) from -= 24*60;
	FOR(i,from,to+1)if(i>=0) busy[i]=true;
}
int r[111111][111];
int f[111111][111];
int fp[111111][111];

vi q;
vector<pii> w;


vector<Dude> d;

int next(int pos){return busy[pos] ? next(pos+1): pos;}

void go(int pos,int xx){
	if(pos==0 || xx<=0) return;
	if(r[pos][xx-1]==r[pos][xx]){
		go(pos,xx-1);
		return;
	}
	if(r[pos][xx]) go(fp[pos][xx],xx-1);
	q.pb(d[f[pos][xx]].id);
	w.pb(pii(next(fp[pos][xx]+1),pos));
}


void print(int x){printf(" %d %02d:%02d",x/24/60,(x%(24*60))/60,x%60);}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>m>>n>>k;
	REP(i,m){
		string s;
		cin>>s;
		iid[s]=i;
	}
	REP(i,m) cin>>t[i];
	REP(i,4){
		int x,y;
		scanf("%d:%d",&x,&y);
		start[i] = x * 60 + y;
		scanf("-%d:%d",&x,&y);
		end[i] = x * 60 + y;
	}
	for(int i=-1;i<=k;i++){
		REP(j,4) mark_busy(start[j] + 24 * 60 * i, end[j] + 24*60*i);
	}
	mark_busy(0,24*60-1);
	busy[0]=0;
	REP(i,n){
		Dude x;
		x.id=i+1;
		d.pb(x);
	}
	sort(all(d));
	int mx=0;
	int pos=0;
	int xx;
	REP(i,d.size()){
		REP(j,51111) r[j][i+1]=r[j][i],f[j][i+1]=f[j][i],fp[j][i+1]=fp[j][i];
		int prev = 59999;
		if(d[i].subj==-1) continue;
		int curr = t[d[i].subj];
		for(int j=d[i].day*24*60 + d[i].t-1;j>=24*60;j--)if(!busy[j]){
			if(prev==59999){
				prev=j-1;
				while(prev>=0 && curr){
					if(!busy[prev]){
						curr--;
						if(curr==0) break;
					}
					prev--;
				}
				if(prev<0) break;
			}else{
				prev--;
				while(prev>=0 && busy[prev]) prev--;
				if(prev<0) break;
			}

			if(r[j][i+1] < r[prev][i] + d[i].money ){
				r[j][i+1] = r[prev][i] + d[i].money;
				f[j][i+1] = i;
				fp[j][i+1] = prev;

				if(r[j][i+1]>mx || r[j][i+1]==mx && pos>j) mx=r[j][i+1],pos=j,xx=i+1;
			}

			if(prev==0) break;
		}
	}

	cout<<mx<<endl;
	if(pos)go(pos,xx);
	cout<<q.size()<<endl;
	REP(i,q.size()){
		cout<<q[i];
		print(w[i].first);
		print(w[i].second);
		puts("");
	}
	
	return 0;
}
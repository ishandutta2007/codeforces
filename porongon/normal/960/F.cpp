#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;


struct GCS {
	set<pair<int,int> > s;
	void add(int c, int l){
		auto x=mp(c,l);
		auto p=s.upper_bound(mp(c,1<<30));
		if(p!=s.begin()&&(--p)->snd>=x.snd)return;
		if(p!=s.end()){
			++p;
			vector<pair<int,int> > z;
			while(p!=s.end()&&p->snd<=x.snd){
				z.pb(*p);
				++p;
			}
			for(auto p:z)s.erase(p);
		}
		s.insert(x);
	}
	int get(int c){
		auto p=s.upper_bound(mp(c,-(1<<30)));
		assert(p!=s.begin());
		return (--p)->snd;
	}
};

GCS w[100005];
int n,m,r;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)w[i].add(-1,0);
	fore(i,0,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);a--;b--;
		int l=w[a].get(c);
		r=max(r,l+1);
		w[b].add(c,l+1);
	}
	printf("%d\n",r);
	return 0;
}
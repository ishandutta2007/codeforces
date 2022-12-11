#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a,qwer=n;i<qwer;i++)
#define pb push_back
#define snd second
#define fst first
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

typedef double tc;
const tc is_query=-1e100;
struct Line {
	tc m,b;
	mutable multiset<Line>::iterator it,end;
	const Line* succ(multiset<Line>::iterator it) const {
		return (++it==end? NULL : &*it);}
	bool operator<(const Line& rhs) const {
		if(rhs.b!=is_query)return m<rhs.m;
		const Line *s=succ(it);
		if(!s)return 0;
		return b-s->b<(s->m-m)*rhs.m;
	}
};
struct HD : public multiset<Line> {
	bool bad(iterator y){
		iterator z=next(y);
		if(y==begin()){
			if(z==end())return false;
			return y->m==z->m&&y->b<=z->b;
		}
		iterator x=prev(y);
		if(z==end())return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(tc m, tc b){
		iterator y=insert((Line){m,b});
		y->it=y;y->end=end();
		if(bad(y)){erase(y);return;}
		while(next(y)!=end()&&bad(next(y)))erase(next(y));
		while(y!=begin()&&bad(prev(y)))erase(prev(y));
	}
};

int n,k;
int y[512][512];
HD w[512];
double r[512];

double inter(Line l0, Line l1){
	return (l1.b-l0.b)/(l0.m-l1.m);
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)fore(j,0,k+1)scanf("%d",&y[i][j]);
	fore(i,0,n){
		r[i]=0.;
		fore(j,1,k+1){
			double a=1.*(y[i][j]-y[i][j-1])/(j-(j-1));
			double b=y[i][j-1]-1.*(j-1)*(y[i][j]-y[i][j-1])/(j-(j-1));
			w[j].add(a,b);
			vector<Line> z(w[j].begin(),w[j].end());
			double x=j-1;
			fore(k,0,z.size()){
				double xx;
				xx=j;
				if(k!=z.size()-1)xx=min(xx,max(j-1.,inter(z[k],z[k+1])));
				r[i]+=(z[k].m*x+z[k].b+z[k].m*xx+z[k].b)*(xx-x)/2;
				x=xx;
			}
		}
	}
	fore(i,0,n){
		double rr=r[i];
		if(i)rr-=r[i-1];
		printf("%.12lf\n",rr);
	}
	return 0;
}
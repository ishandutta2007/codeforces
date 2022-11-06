#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

#define x first
#define y second

pp operator+(pp a,pp b){ return {a.x+b.x, a.y+b.y}; }
pp operator-(pp a,pp b){ return {a.x-b.x, a.y-b.y}; }

ll cross(pp a,pp b,pp c){
	b=b-a; c=c-a;
	return b.x*1LL*c.y - b.y*1LL*c.x;
}

bool hully(pp a,pp b,pp c){
	ll t=cross(a,b,c);
	if(t!=0) return t>0;
	return abs(b.x-a.x) < abs(c.x-a.x);
}

#define stack namseo
int stack[100010];
int top;
int n;
int A, B;
pp data[100010];

void hull(){
	auto it = min_element(data+1, data+n+1);
	swap(*it, data[1]);
	sort(data+2, data+n+1, [&](const pp& a, const pp& b){
		return hully(data[1], a, b);
	});

	stack[top++]=1;
	for(int i=2; i<=n; ++i){
		while(top>=2 && cross(data[stack[top-2]], data[stack[top-1]],
			data[i])<=0) --top;
		stack[top++]=i;
	}
}

struct vt {
	ll a,b,c;
	vt(){ a=b=c=0; }
	vt(ll a,ll b,ll c=1):a(a), b(b), c(c){}
	vt cross(vt r){
		return {b*r.c-c*r.b, c*r.a-a*r.c, a*r.b-b*r.a};
	}
} hp[100010];

ll sign(ll x){
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}

int main(){
	read(n,A,B);
	for(int i=1; i<=n; ++i) read(data[i]);
	sort(data+1, data+n+1);
	n=unique(data+1, data+n+1)-data-1;
	hull();
	double ans=1e300;
	for(int i=0; i<top; ++i){
		hp[i]=vt(data[stack[i]].x, data[stack[i]].y);
	}
	for(int i=1; i<=n; ++i){
		ans=min(ans, max(A*1.0/data[i].x, B*1.0/data[i].y));
	}
	vt xl(B, -A, 0);
	for(int i=0; i<top; ++i){
		vt l = hp[i].cross(hp[(i+1)%top]);
		vt cp = xl.cross(l);
		if(cp.c==0) continue;
		if(sign(data[stack[i        ]].x*cp.c - cp.a)*
		   sign(data[stack[(i+1)%top]].x*cp.c - cp.a) <= 0 &&
		   sign(data[stack[i        ]].y*cp.c - cp.b)*
		   sign(data[stack[(i+1)%top]].y*cp.c - cp.b) <= 0){
		   	ans = min(ans, A*1.0*cp.c*1.0/cp.a);
		}
	}
	printf("%.15f\n",ans);
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
#define pow PORONGON
using namespace std;

typedef long long ll;

vector<int> g[200005];
int n;
stack<int> st;
int lc,nc;
bool v[200005];

void dfs(int x, int f){
	//printf("%d\n",x+1);
	st.push(x);
	v[x]=true;
	nc++;
	int w=0;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f&&w==0){w=1;continue;}
		if(v[y]){
			if(!lc){
				//printf(" %d\n",y+1);
				while(st.top()!=y)st.pop(),lc++;
				lc++;
			}
		}
		else dfs(y,x);
	}
	if(!st.empty()&&st.top()==x)st.pop();
}

ll pow(ll a, int b){
	if(b==0)return 1;
	if(b%2)return (a*pow(a,b-1))%MOD;
	ll w=pow(a,b/2);
	return (w*w)%MOD;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);x--;
		g[i].pb(x);
		g[x].pb(i);
	}
	ll r=1;
	fore(i,0,n)if(!v[i]){
		nc=lc=0;
		while(!st.empty())st.pop();
		dfs(i,-1);
		//printf(" %d %d\n",nc,lc);
		r*=(pow(2,nc)+MOD-pow(2,nc-lc+1))%MOD;
		r%=MOD;
	}
	printf("%d\n",(int)r);
	return 0;
}
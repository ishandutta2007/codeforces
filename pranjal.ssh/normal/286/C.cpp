#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;scanf("%d",&__T);FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
const int N = 1e6;
int lol[N+1];
int p[N+1];vi a;
int main()
{
    int n;scanf("%d",&n);FOR(i,0,n-1)scanf("%d",p+i),a.pb(p[i]);
    
    TCASE{int x;scanf("%d",&x);lol[x-1]++;}
    stack<int> s;
    bool can=1;
    FOR(i,0,n-1){
    	s.push(i);
    	if(!lol[i])continue;
    	s.pop();
    	stack<int> yo;
    	can=0;
    	while(1){
    		if(s.empty())break;
    		int x = s.top();
    		s.pop();
    		if(p[x]==p[i] and yo.empty()){can=1;a[i]*=-1;break;}
    		if(yo.empty()){yo.push(x);continue;}
    		if(p[yo.top()]==p[x])a[yo.top()]*=-1,yo.pop();
    		else yo.push(x);
    	}
    	if(!can){break;}
    }
    stack<int> yo;
    while(1){
    	if(s.empty())break;
    	int x = s.top();
    	s.pop();
    	if(yo.empty()){yo.push(x);continue;}
    	if(p[yo.top()]==p[x])a[yo.top()]*=-1,yo.pop();
    	else yo.push(x);
    }
    can&=yo.empty();
    if(!can)cout<<"NO";
    else {
    	cout<<"YES\n";
        FOR(i,0,n-1)cout<<a[i]<<" ";
    }
	return 0;
}
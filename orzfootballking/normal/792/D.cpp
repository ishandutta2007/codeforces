#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,qu,u;
string s;
P<int,int> p[100005];
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>qu;
	FOR(i,1,qu){
		cin>>u>>s;
		string t="";
		int l=1,r=n,mid;
		while(1){
			mid=(l+r)/2;
			if(mid==u){
				break;
			}else if(mid<u){
				l=mid+1;t+="R";
			}else{
				r=mid-1;t+="L";
			}
		}
		s=t+s;l=1;r=n;
		int q=1;
		p[1]=MP(1,n);
		FOR(j,0,s.size()-1){
			if(s[j]=='L'){
				if(p[q].F==p[q].S)continue;
				q++;
				p[q]=p[q-1];
				p[q].S=(p[q].F+p[q].S)/2-1;
			}else if(s[j]=='R'){
				if(p[q].F==p[q].S)continue;
				q++;
				p[q]=p[q-1];
				p[q].F=(p[q].F+p[q].S)/2+1;
			}else{
				if(q==1)continue;
				q--;
			}
		}
		cout<<(p[q].F+p[q].S)/2<<'\n';
	}
	RE 0;
}
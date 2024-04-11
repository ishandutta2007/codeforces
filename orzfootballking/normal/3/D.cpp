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
int n,a[50005],b[50005];
priority_queue<P<int,int> > q;
string s,as;
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>s;
	if(s.size()%2){
		cout<<-1;RE 0;
	}
	n=s.size();
	int p=0,ans=0,anf=0;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			p++;
			cin>>a[p]>>b[p];
			ans+=b[p];
			q.push(MP(b[p]-a[p],i));
			as+=')';anf--;
		}else if(s[i]=='('){
			anf++;as+='(';
		}else{
			anf--;as+=')';
		} 
		if(anf<0){
			if(!q.size()){
				cout<<-1;RE 0;
			}
			P<int,int> cur=q.top();q.pop();
			ans-=cur.F;
			as[cur.S]='(';
			anf+=2;
		}
	}
	if(anf){
		cout<<-1;
	}else cout<<ans<<'\n'<<as;
	RE 0;
}
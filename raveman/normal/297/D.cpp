#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
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

int n,m,k;

string s[2222];
string ss[2222];

vector<vi> trans(vector<vi> a){
	vector<vi> ans(a[0].size());
	REP(i,a.size()){
		REP(j,a[i].size()){
			ans[j].pb(a[i][j]);
		}
	}
	return ans;
}

void trans(){
	REP(i,2*m-1){
		if(i%2==0) ss[i]=string(n-1,' ');
		else ss[i]=string(n,' ');
	}
	REP(i,2*n-1){
		REP(j,s[i].size()){
			char c = s[i][j];
			if(i%2==0){
				ss[2*j+1][i/2]=c;
			}else{
				ss[2*j][i/2] = c;
			}
		}
	}
}

vi solve(string s){
	//cout<<"SOLVE "<<s<<endl;
	vi res;
	res.pb(0);
	REP(i,s.size())if(s[i]=='E') res.pb(res.back());
	else res.pb(1-res.back());
	//cout<<res.size()<<endl;
	return  res;
}

int numg(vi v1, vi v2, string s){
	int x = 0;
	REP(i,s.size()){
		if(s[i]=='E' && v1[i]==v2[i]) x++;
		if(s[i]=='N' && v1[i]!=v2[i]) x++;
	}
	return x;
}

int NUM;
vector<vi> solve(string *s, int n,int m){
	//puts("SOLVE");
	//cout<<n<<' '<<m<<endl;
	//REP(i,2*n-1)cout<<s[i]<<endl;
	NUM=0;
	vector<vi> ans;
	int good = 0;
	REP(i,n){
		vi t = solve(s[2*i]);
		vi t2 = t;
		REP(i,t2.size()) t2[i]^=1;
		NUM+=s[2*i].size();
		if(i==0) ans.pb(t);
		else{
			NUM+=max(numg(ans.back(),t,s[2*i-1]),numg(ans.back(),t2,s[2*i-1]));
			if(numg(ans.back(),t,s[2*i-1]) > numg(ans.back(),t2,s[2*i-1])) ans.pb(t);
			else ans.pb(t2);
		}
	}
	//REP(
	return ans;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	int total = 0;
	REP(i,2*n-1){
		cin>>s[i],total+=s[i].size();
	}

	if(k==1){
		int num = 0;
		REP(i,2*n-1)REP(j,s[i].size())if(s[i][j]=='N')num++;
		num=total-num;
		if(num*4 >= 3 * total){
			puts("YES");
			REP(i,n){
				REP(j,m){
					if(j)printf(" ");
					printf("1");
				}
				puts("");
			}
		}else{
			puts("NO");
		}
	}else{
		vector<vi> ans = solve(s,n,m);
		int n1 = NUM;
		trans();
		vector<vi> ans2 = solve(ss,m,n);
		int n2 = NUM;
		//cout<<n1<<' '<<n2<<endl;
		if(n2>n1){
			ans = ans2;
			ans = trans(ans);
		}
		puts("YES");
		REP(i,ans.size()){
			REP(j,ans[i].size()){
				if(j)printf(" ");
				printf("%d",ans[i][j]+1);
			}
			puts("");
		}		
	}
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
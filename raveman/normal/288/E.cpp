#pragma comment(linker, "/STACK:60777216")  

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

const int mod = 1000000007;

ll q[111111];
ll q1[111111];
ll q2[111111];
ll q3[111111];
ll sum[111111];
ll all4[111111];
ll all7[111111];
ll qp2[111111];
ll qp10[111111];

string l,r;

struct Res{
	ll total;
	ll num;
	ll sum;
	ll up;
	Res(){total=num=sum=up=0;}
};

void add(ll &x, ll y){
	y%=mod;
	if(y<0) y+=mod;
	x+=y;	
	if(x>=mod) x-=mod;
}

Res solve(string &s, int pos){
	Res res;
	if(pos>=s.size()){
		res.num=1;
		return res;
	}
	int st = s.size() - pos - 1;
	Res t = solve(s,pos+1);
	if(s[pos]=='4'){
		add(res.total, t.total);
		add(res.num, t.num);
		add(res.total, 4 * qp10[st] % mod * 4 % mod * qp10[st] % mod * (t.num-1)% mod );
		add(res.total, 4 * qp10[st]% mod  * (t.sum - all4[st])% mod );
		add(res.total, 4 * qp10[st]% mod  * (t.sum - t.up)% mod );
		add(res.sum, t.sum);
		add(res.sum, 4 * qp10[st]% mod  * t.num% mod );
	}
	if(s[pos]=='7'){
		add(res.num, qp2[st]);
		add(res.num, t.num);
		
		add(res.sum, sum[st]);
		add(res.sum, 4 * qp10[st] % mod * qp2[st] % mod);
		add(res.sum, t.sum);
		add(res.sum, 7 * qp10[st] % mod * t.num % mod);

		add(res.total,q1[st+1]);
		add(res.total,q3[st+1]);

		add(res.total,t.total);
		add(res.total, 7 * qp10[st] % mod * 7 % mod * qp10[st] % mod * (t.num-1)% mod );
		add(res.total, 7 * qp10[st]% mod  * (t.sum - all4[st])% mod );
		add(res.total, 7 * qp10[st]% mod  * (t.sum - t.up)% mod);		
	}
	add(res.up, t.up);
	add(res.up, (s[pos]-'0') * qp10[st]%mod);
	
	return res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	q[0] = 0;
	sum[0] = 0;
	qp2[0]=qp10[0]=1;
	FOR(i,1,111111){
		qp2[i]=qp2[i-1]*2%mod;
		qp10[i]=qp10[i-1]*10%mod;
		all4[i] = (all4[i-1]*10+4)%mod;
		all7[i] = (all7[i-1]*10+7)%mod;

		sum[i] = sum[i-1] + 4 * qp2[i-1] % mod * qp10[i-1] % mod + sum[i-1] + 7 * qp2[i-1] % mod * qp10[i-1] % mod;
		sum[i] %= mod;
		
		ll t1 = q[i-1] + 4 * qp10[i-1] % mod * (sum[i-1] - all4[i-1]) % mod + 4 * qp10[i-1]%mod*(sum[i-1]-all7[i-1])%mod + 4 * 4 * qp10[i-1]%mod*qp10[i-1]%mod*(qp2[i-1]-1)%mod;
		ll t2 = q[i-1] + 7 * qp10[i-1]%mod * (sum[i-1] - all4[i-1])%mod + 7 * qp10[i-1]%mod*(sum[i-1]-all7[i-1])%mod + 7 * 7 * qp10[i-1]%mod*qp10[i-1]%mod*(qp2[i-1]-1)%mod;
		ll t3 = (4*qp10[i-1]+all7[i-1])%mod*((7*qp10[i-1]+all4[i-1])%mod);
		t1%=mod;if(t1<0) t1+=mod;
		t2%=mod;if(t2<0) t2+=mod;
		t3%=mod;if(t3<0) t3+=mod;
		q1[i] = t1%mod;
		q2[i] = t2%mod;
		q3[i] = t3%mod;
		q[i]= (t1+t2+t3)%mod;
		if(q[i]<0) q[i]+=mod;
		//
		//cout<<i<<' '<<q[i]<<endl;//<<"=" <<t1<<' '<<t2<<' '<<t3<<endl;
	}

	cin>>l>>r;

	Res res1 = solve(r,0);
	Res res2 = solve(l,0);
	//cout<<res1.total<<' '<<res2.total<<endl;
	ll res = res1.total - res2.total;
	if (res < 0) res += mod;
	cout<<res<<endl;

	return 0;
}
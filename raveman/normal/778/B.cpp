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
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

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

int n,m;
string VAR_VAL[5555];
string operation[5555];
int op1[5555],op2[5555];
map<string,int> w;
bool z0[5555];
bool z1[5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	w["?"]=-1;
	REP(i,n){
		string v,tmp,val;
		cin>>v>>tmp>>val;
		w[v] = i;
		if(isdigit(val[0])){
			VAR_VAL[i] = val;
		}else{
			string op,val2;
			cin>>op>>val2;
			op1[i] = w[val];
			op2[i] = w[val2];
			operation[i] = op;
		}
	}
	string mn,mx;
	REP(i,m){
		int n0=0,n1=0;
		REP(j,n){
			if(VAR_VAL[j].empty()){
				if(operation[j]=="AND"){
					z0[j] = (op1[j]==-1?0:z0[op1[j]]) & (op2[j]==-1?0:z0[op2[j]]);
					z1[j] = (op1[j]==-1?1:z1[op1[j]]) & (op2[j]==-1?1:z1[op2[j]]);
				}
				if(operation[j]=="OR"){
					z0[j] = (op1[j]==-1?0:z0[op1[j]]) | (op2[j]==-1?0:z0[op2[j]]);
					z1[j] = (op1[j]==-1?1:z1[op1[j]]) | (op2[j]==-1?1:z1[op2[j]]);
				}
				if(operation[j]=="XOR"){
					z0[j] = (op1[j]==-1?0:z0[op1[j]]) ^ (op2[j]==-1?0:z0[op2[j]]);
					z1[j] = (op1[j]==-1?1:z1[op1[j]]) ^ (op2[j]==-1?1:z1[op2[j]]);
				}
			}else{
				z1[j] = z0[j] = VAR_VAL[j][i]-'0';
			}
			if(z0[j]) n0++;
			if(z1[j]) n1++;
		}
		if(n0<=n1) mn.pb('0'); else mn.pb('1');
		if(n0>=n1) mx.pb('0'); else mx.pb('1');
	}
	cout<<mn<<endl<<mx<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
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

int n;
int tx[11111];
int x[11111];
int y[11111];
int ty[11111];
int base[33];
bool u[11111];
bool uy[11111];

bool check(vector<pii> v){
	REP(i,v.size()){
		tx[v[i].first]^=tx[v[i].second];
	}
	REP(i,n)if(tx[i]!=ty[i]){
		puts("FUCK");
		while(1);
		return false;
	}
	return true;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	//start:
	
	cin>>n;
	REP(i,n)scanf("%d",x+i);
	REP(i,n)scanf("%d",y+i);
	
	//n=rand()%10+1;
	//n=rand()%10+1;
	//REP(i,n)x[i]=rand()%40;
	//REP(i,n)y[i]=rand()%10,x[i]=rand()%10;
	//REP(j,100)y[rand()%n]^=y[rand()%n];

	//REP(i,n)cout<<x[i]<<' ';puts("");
	//REP(j,n)cout<<y[j]<<' ';puts("");

	CL(base,-1);
	CL(u,false);CL(uy,false);
	REP(i,n)tx[i]=x[i];
	REP(i,n)ty[i]=y[i];

	vector<pii> v;
	for(int bit=0;bit<30;bit++){
		REP(i,n){
			if((x[i]&(1<<bit)) && !u[i]){
				u[i]=true;
				base[bit]=i;
				REP(j,n)if(j!=i)if(x[j]&(1<<bit)){
					x[j]^=x[i];
					v.pb(pii(j,i));
				}
				break;
			}
		}
	}
	bool good = true;

	REP(i,n)if(!u[i]){
		while(x[i]);
		REP(j,30)if(base[j]!=-1){
			if(y[i]&(1<<j)){
				x[i]^=x[base[j]];
				v.pb(pii(i,base[j]));
			}
		}
		if(x[i]!=y[i]){
			good=false;
			break;
		}
	}



	if (good){
		vi pos;
		REP(i,n)if(u[i])pos.pb(i);
		vector<pii> inv;
		for(int bit=0;bit<30;bit++){
			REP(i,pos.size()){
				if((y[pos[i]]&(1<<bit)) && !uy[pos[i]]){
					uy[pos[i]]=true;
					REP(j,pos.size())if(j!=i)if(y[pos[j]]&(1<<bit)){
						y[pos[j]]^=y[pos[i]];
						inv.pb(pii(pos[j],pos[i]));
					}
					break;
				}
			}
		}
		//REP(i,pos.size()) cout<<x[i]<<' '<<y[i]<<"  ! "<<endl;//<<' ';puts("");
		/*bool changes = true;
		while(changes){
			changes=false;
			REP(i,pos.size()){
				if(y[pos[i]]==0) continue;
				bool f = 0;
				REP(j,pos.size())if(x[pos[j]]==y[pos[i]]){
					//cout<<i<<' '<<j<<endl;
					if(i==j){f=1;break;}
					changes=true;
					swap(y[pos[i]],y[pos[j]]);
					inv.pb(pii(pos[i],pos[j]));
					inv.pb(pii(pos[j],pos[i]));
					inv.pb(pii(pos[i],pos[j]));
					f=1;
					break;
				}
				if(!f){good=0;break;}
			//	cout<<"new"<<endl;
				//REP(i,pos.size()) cout<<x[i]<<' '<<y[i]<<"  ! "<<endl;//<<' ';puts("");
			}
		}*/
		///REP(i,pos.size()) cout<<pos[i]<<' ';puts("");
		//REP(i,pos.size()) cout<<y[i]<<' ';puts("");
		//REP(i,pos.size()) cout<<x[i]<<' ';puts("");
		REP(i,pos.size()){
			if(y[pos[i]]==0)continue;
			bool f = 0;
			REP(bit,30)if(base[bit]!=-1 && (y[pos[i]]&(1<<bit))){
				f=1;
				//cout<<bit<<' '<<base[bit]<<endl;
				if(base[bit]!=pos[i]){
					REP(bit2,30)if(base[bit2]==pos[i]){
						//cout<<"R "<<pos[i]<<' '<<base[bit]<<endl;
						v.pb(pii(pos[i],base[bit]));
						v.pb(pii(base[bit],pos[i]));
						v.pb(pii(pos[i],base[bit]));
						swap(x[pos[i]],x[base[bit]]);
						swap(base[bit],base[bit2]);
						
						break;
					}
				}
				//cout<<"Z " << y[pos[i]]<<' '<<x[pos[i]]<<' '<<pos[i]<<endl;
				REP(bit2,30)if(base[bit2]!=-1 && ((y[pos[i]]^x[pos[i]])&(1<<bit2))){
					x[pos[i]]^=x[base[bit2]];
					//cout<<"W " <<pos[i]<<' '<<base[bit2]<<' '<<(y[pos[i]]^x[pos[i]])<<endl;
					v.pb(pii(pos[i],base[bit2]));
				}
				break;
			}
			if(!f){good=0;break;}
			if(x[pos[i]]!=y[pos[i]]){good=0;break;}
		}
		REP(i,pos.size()){
			if(y[pos[i]]) continue;
			inv.pb(pii(pos[i],pos[i]));
		}
		
		reverse(inv.begin(),inv.end());
		REP(i,inv.size()){
			v.pb(inv[i]);
		}
	}

	if(!good){
		puts("-1");

//		while(1);
	}
	else{
		cout<<v.size()<<endl;
		REP(i,v.size()) printf("%d %d\n",v[i].first+1,v[i].second+1);

	//	check(v);
	}

//	goto start;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
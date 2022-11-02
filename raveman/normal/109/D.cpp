#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n;
int a[111111];
int b[111111];
int c[111111];

bool l(int x){
	while(x){
		if(x%10!=4 && x%10!=7) return 0;
		x/=10;
	}
	return 1;
}

vector<pii> res;

set<pii> q;

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n){
		b[i]=a[i];
		c[i]=b[i];
		q.insert(pii(a[i],i));
	}
	sort(b,b+n);
	bool good = 1;
	FOR(i,1,n)if(a[i]<a[i-1])good=0;
	if(good)puts("0");
	else{
		int l_pos=-1;
		bool hasl = 0;
		REP(i,n)if(l(a[i])) hasl=1,l_pos=i;
		if(!hasl) puts("-1");
		else{
			int pos = 0;
			while(pos<n){
				if(b[pos] == a[l_pos] && (pos==0 || b[pos-1]!=b[pos])) {pos++;continue;}

				pii val = *q.lower_bound(pii(b[pos],0));
				if(val.second == pos){
					q.erase(pii(b[pos],pos));
					pos++;
				}else{
					if(val.second == l_pos)
						val = *q.lower_bound(pii(val.first,val.second+1));

					if(val.second == pos){
						q.erase(pii(b[pos],pos));
						pos++;
					}else if(l_pos==pos){
						q.erase(pii(a[l_pos],l_pos));
						q.erase(pii(a[val.second],val.second));

						res.pb(pii(l_pos,val.second));
						swap(a[l_pos],a[val.second]);

						q.insert(pii(a[val.second],val.second));
						l_pos = val.second;
					}else{
						q.erase(pii(a[l_pos],l_pos));
						q.erase(pii(a[pos],pos));
						q.erase(pii(a[val.second],val.second));

						res.pb(pii(l_pos,pos));
						swap(a[l_pos],a[pos]);
						res.pb(pii(pos,val.second));
						swap(a[pos],a[val.second]);

						q.insert(pii(a[l_pos],l_pos));
						q.insert(pii(a[val.second],val.second));
						l_pos = val.second;
					}

					pos ++;
				}
			}

			cout<<res.size()<<endl;
			REP(i,res.size()){
				printf("%d %d\n",res[i].first+1,res[i].second+1);
				//cout<<"			"<<c[res[i].first]<<' '<<c[res[i].second]<<endl;
				swap(c[res[i].first],c[res[i].second]);
				//REP(j,n)cout<<c[j]<<' ';
				//puts("");
			}
		}
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}
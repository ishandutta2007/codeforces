#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

int d;
string s;
ll h1[555555];
ll r1[555555];
ll in[555555];

const int M1 = 31;

const ll MOD1 = 1000000007;

ll s1[555555];

int START;
bool addone(int pos){
	while(pos>=0 && s[pos]=='z'){
		s[pos]='a';
		pos--;
	}
	if(pos<0) return 0;
	s[pos]++;
	START = pos;
	return 1;
}

int getH(int pos,int len){
	ll H1 = h1[pos];
	if(pos-len>=0) H1 -= h1[pos-len]*s1[len];
	H1 %= MOD1;
	if(H1<0) H1+=MOD1;
	return H1;
}
ll qp(ll c,ll st){
	ll r = 1;
	while(st){
		if(st&1) r*=c,r%=MOD1;
		c*=c,c%=MOD1;
		st>>=1;
	}
	return r;
}
int getHr(int pos,int len){
	ll H1 = r1[pos];
	if(pos-len>=0) H1 -= r1[pos-len];
	H1 %= MOD1;
	if(H1<0) H1 += MOD1;
	if(in[pos-len+1]==-1)
		in[pos-len+1]=qp(s1[pos-len+1],MOD1-2);
	H1 *= in[pos-len+1];
	H1 %= MOD1;
	return H1;
}

bool ispal(int p1,int p2,int len){
	return getHr(p1,len)==getH(p2,len);
}

bool ispal(int pos,int len){
	//cout<<"ISP "<<pos<<' '<<len<<endl;
	if(len%2){
		return ispal(pos,pos-len/2-1,len/2);
	}else{
		return ispal(pos,pos-len/2,len/2);
	}
}
bool ispal(int pos){

	if(pos+1>=d && ispal(pos,d)) return 1;
	if(pos+1>=d+1 && ispal(pos,d+1)) return 1;
	return 0;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	s1[0]=1;
	CL(in,-1);
	FOR(i,1,400001) s1[i]=s1[i-1]*M1,s1[i]%=MOD1;
	
	cin>>d>>s;
	if(d==1 || !addone(s.size()-1)){
		puts("Impossible");
		return 0;
	}

	//s="";
	//REP(i,400000) s.pb(char('a'+rand()%26));
	int clFrom = s.size();
	for(int i=0;i<s.size();i++){
		if(i>=clFrom) s[i]='a';
		h1[i]=(i?h1[i-1]:0)*M1 + s[i]-'a'+1;h1[i]%=MOD1;
		r1[i]=(i?r1[i-1]:0) + (s[i]-'a'+1)*s1[i]; r1[i]%=MOD1;
		if(ispal(i)){
			if(!addone(i)){
				puts("Impossible");
				return 0;
			}
			clFrom = START+1;
			i = START-1;
		}
	}
	cout<<s<<endl;

//	cout<<r1[0]<<' '<<r1[1]<<endl;
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}